#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <regex>
#include <boost/regex.hpp>
#include <memory>
#include <filesystem>
#include <iomanip>
#include <unistd.h>
#include "resources.hpp"
#include "params.hpp"

class Kat {

  std::string COLOR_WHITE;
  std::string COLOR_WHITE_BOLD;
  std::string COLOR_PINK;
  std::string COLOR_RESET;
  std::string COLOR_GREEN_HEX;
  std::string COLOR_YELLOW_HEX;
  std::string COLOR_BLUE_LIGHT;
  std::string COLOR_GRAY_FOUR;
  std::string COLOR_GRAY_MANY;
  std::string COLOR_ORANGE_HEX;
  std::string COLOR_PURPLE_HEX;
  std::string COLOR_REMOVE;

  std::string m_filetype;
  const std::string m_filename;
  bool m_pager;

  int width_terminal;

  void start_end(bool);
  void display(const std::string&,int);
  void get_highlight(std::string&);
  void check_pager();
  void help();

  public:
    Kat(const std::string, const bool);
    void print_code();
};
