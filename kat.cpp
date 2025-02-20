#include "kat.hpp"

namespace fs = std::filesystem;

Kat::Kat(const std::string filename, const bool pager) : m_filename(filename), m_pager(pager){
  m_filetype = fs::path(m_filename).extension().string();
  if(!m_filetype.empty() && m_filetype.front() == '.') {
    m_filetype.erase(0, 1);
  }
  width_terminal = {40};

  if(m_pager == 1){
    COLOR_WHITE      = "";
    COLOR_WHITE_BOLD = "";
    COLOR_PINK       = "";
    COLOR_RESET      = "";
    COLOR_GREEN_HEX  = "";
    COLOR_YELLOW_HEX = "";
    COLOR_BLUE_LIGHT = "";
    COLOR_GRAY_FOUR  = "";
    COLOR_GRAY_MANY  = "";
    COLOR_ORANGE_HEX = "";
    COLOR_PURPLE_HEX = "";
    COLOR_REMOVE     = "";
  }else{
    COLOR_WHITE      = "\033[38;2;255;255;255m";
    COLOR_WHITE_BOLD = "\033[1;38;2;255;255;255m";
    COLOR_PINK       = "\033[38;2;249;38;114m";
    COLOR_RESET      = "\033[0m";
    COLOR_GREEN_HEX  = "\033[38;2;166;226;46m";
    COLOR_YELLOW_HEX = "\033[38;2;230;219;116m";
    COLOR_BLUE_LIGHT = "\033[38;2;102;217;239m";
    COLOR_GRAY_FOUR  = "\033[38;2;68;68;68m";
    COLOR_GRAY_MANY  = "\033[38;2;117;113;94m";
    COLOR_ORANGE_HEX = "\033[38;2;253;151;31m";
    COLOR_PURPLE_HEX = "\033[38;2;190;132;255m";
    COLOR_REMOVE     = "\033\\[[0-9;]*m";
  }
}

void Kat::print_code(){

  help();

  std::ifstream file(m_filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << m_filename << std::endl;
    std::exit(1);
  }

  std::string line;
  int number = 1;
  start_end(true);
  while(std::getline(file, line)){
    display(line, number++);
  }
  start_end(false);

  file.close();
}

void Kat::start_end(bool p){
  if(p){ // header
         // start line
    for(int i {}; i < 7; ++i){
      std::cout << COLOR_GRAY_FOUR << "\u2500";
    }
    std::cout << "\u252C";
    for(int i {}; i < width_terminal; ++i){
      std::cout << "\u2500";
    }
    std::cout << COLOR_RESET << std::endl;

    // line filetype and filename
    std::cout << COLOR_GRAY_FOUR << std::setw(1) << std::string{""}
    << COLOR_WHITE << std::setw(2) << std::string{""} 
    << unicode(m_filetype) << std::setw(2) << std::string{""}
    << COLOR_GRAY_FOUR << std::setw(1) << std::string{""} 
    << "\u2502" << std::setw(1) << std::string{""}
    << COLOR_WHITE_BOLD << m_filename 
      << COLOR_RESET << std::endl;

    // final header
    for(int i {}; i < 7; ++i){
      std::cout << COLOR_GRAY_FOUR << "\u2500";
    }
    std::cout << "\u253C";
    for(int i {}; i < width_terminal; ++i){
      std::cout << "\u2500";
    }
    std::cout << COLOR_RESET << std::endl;

  }else{ // end line
    for(int i {}; i < 7; ++i){
      std::cout << COLOR_GRAY_FOUR << "\u2500";
    }
    std::cout << "\u2534";
    for(int i {}; i < width_terminal; ++i){
      std::cout << "\u2500";
    }
    std::cout << COLOR_RESET << std::endl;
  }
}

void Kat::display(const std::string& line, int number){
  std::string highlight = line;

  get_highlight(highlight);
  // lines number
  // TODO: number < 100
  if(number < 10){
    std::cout << std::setw(3) << std::string{""} 
    << COLOR_GRAY_FOUR << number << std::setw(3) 
      << std::string{""} << "\u2502" << std::setw(1) 
      << std::string{""} << COLOR_RESET << highlight << '\n';
  }else{
    std::cout << std::setw(2) << std::string{""} 
    << COLOR_GRAY_FOUR << number << std::setw(3) 
      << std::string{""} << "\u2502" << std::setw(1) 
      << std::string{""} << COLOR_RESET << highlight << '\n';
  }
}

void Kat::get_highlight(std::string& line){

  auto params = std::make_unique<Params>(m_filetype);

  static bool in_multiline_comment = false;

  // for multiline
  if (in_multiline_comment) {
    auto end_pos = line.find(Params::multicom2);
    if (end_pos != std::string::npos) {
      line.replace(0, end_pos + 2, std::string(COLOR_GRAY_FOUR) + line.substr(0, end_pos + 2) + COLOR_RESET);
      in_multiline_comment = false;
      std::string rest = line.substr(end_pos + 2);
      get_highlight(rest);
      line = line.substr(0, end_pos + 2) + rest;
    } else {
      line = std::string(COLOR_GRAY_FOUR) + line + COLOR_RESET;
      return;
    }
  }

  line = boost::regex_replace(line, boost::regex(Params::comment), COLOR_GRAY_FOUR + "$&" + COLOR_RESET);

  auto start_pos = line.find(Params::multicom1);
  if (start_pos != std::string::npos) {
    line.replace(start_pos, 2, std::string(COLOR_GRAY_FOUR) + Params::multicom1);
    in_multiline_comment = true;
  }

  line = boost::regex_replace(line, boost::regex(Params::fn1), COLOR_GREEN_HEX + "$1" + COLOR_RESET + "(");
  line = boost::regex_replace(line, boost::regex(Params::fn2), "$1 " + COLOR_GREEN_HEX + "$2" + COLOR_RESET + "(");

  std::vector<std::string> special = Params::special;
  for (const auto& keyword : special) {
    line = boost::regex_replace(line, boost::regex(keyword + "\\b"), COLOR_PINK + "$&" + COLOR_RESET);
  }

  std::vector<std::string> keywords = Params::keywords;
  for (const auto& keyword : keywords) {
    line = boost::regex_replace(line, boost::regex("\\b" + keyword + "\\b"), COLOR_BLUE_LIGHT + "$&" + COLOR_RESET);
  }

  line = boost::regex_replace(line, boost::regex(Params::header_and_url), COLOR_YELLOW_HEX + "$&" + COLOR_RESET);

  line = boost::regex_replace(line, boost::regex(Params::args_fn), COLOR_ORANGE_HEX + "$1" + COLOR_RESET);

  line = boost::regex_replace(line, boost::regex("(\".*?)(" + COLOR_REMOVE + ")+(.*?\")"), "$1$3");
  line = boost::regex_replace(line, boost::regex(Params::literal_str), COLOR_YELLOW_HEX + "$&" + COLOR_RESET);

  line = boost::regex_replace(line, boost::regex(Params::str_newline), COLOR_PURPLE_HEX + "$&" + COLOR_YELLOW_HEX);
  //line = boost::regex_replace(line, boost::regex("([\\{\\}\\(\\)\\=\\+\\-\\^\\*\\/])"), std::string(COLOR_WHITE) + "$1" + COLOR_RESET);
}

void Kat::help(){
  if(!m_filename.empty() && m_filename.front() == '-'){
    if(m_filename == "--help" || m_filename == "-h"){
      std::cout << "Usage:\n";
      std::cout << std::setw(2) << "" << "kat [options] file\n";
      std::cout << std::setw(4) << "" << "--help, -h      This help.\n";
      std::cout << std::setw(4) << "" << "--version, -v   Check version.\n";
    }else if(m_filename == "--version" || m_filename == "-v"){
      std::cout << "kat VERSION 0.1\n";
    }else{
      std::cerr << "Invalid parameter.\n";
      std::exit(1);
    }
    std::exit(0);
  }
}
