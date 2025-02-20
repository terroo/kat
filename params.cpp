#include "params.hpp"

Params::Params(const std::string& filetype) : m_filetype(filetype){

  if(m_filetype == "c" || m_filetype == "cpp" || m_filetype == "hpp" || m_filetype == "h"){
    c_cpp();
  }else if(m_filetype == "java"){
    java();
  }else if(m_filetype == "py"){
    python();
  }else if(m_filetype == "js" || m_filetype == "ts"){
    python();
  }else if(m_filetype == "cs"){
    python();
  }else{
    file_text();
  }
}

void Params::c_cpp(){
  special =  {"#include", "#define", "return", "register", "if", "else", "inline", 
    "class", "#pragma", "using", "decltype", "new", "delete", 
    "typedef", "class", "static", "using", "switch", "case", 
    "throw",  "catch", "try", "for", "while", "constexpr", 
    "consteval", "unsigned", "friend", "#if", "#elif", "#ifdef", 
    "#ifndef", "#define"};
  keywords = {"int", "char", "double", "float", "void", "printf", "auto", 
    "const", "public", "private", "protected", "static", "namespace", 
    "short", "extends", "this", "enum", "double", "do", "break", 
    "continue", "byte", "boolean", "assert", "long", "enum", 
    "do", "break", "continue", "virtual", "bool", "sizeof", "stuct", 
    "reinterpret_cas", "static_cast"
  };
  comment = "//.*";
  multicom1 = "/*";
  multicom2 = "*/";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::java(){
  special =  { "import", "transient", "synchronized", "volatile", "if", "else", 
    "abstract", "class", "static", "using", "switch", "case", "throw", "interface",
    "catch", "try", "for", "while"
  };
  keywords = {"int", "char", "void", "printf", "String", "final", "public", 
    "private", "protected", "float", "long", "new", "return", "short", "extends",
    "this", "enum", "double", "do", "break", "continue", "byte", "boolean", "assert"
  };
  comment = "//.*";
  multicom1 = "/*";
  multicom2 = "*/";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::file_text(){
  special = {};
  keywords = {};
  comment = "@@@@";
  multicom1 = "@@@@";
  multicom2 = "@@@@";
  fn1 = "@@@@";
  fn2 = "@@@@";
  str_newline = "@@@@";
  literal_str = "@@@@";
  args_fn = "@@@@";
  header_and_url = "@@@@";
}

void Params::python(){
  special =  { "import", "def", "synchronized", "volatile", "if", "else", 
    "elif", "class", "lambda", "True", "False", "in", "with", 
    "del", "from", "for", "while"
  };
  keywords = {"do", "break", "continue", "byte", "boolean", "assert", "as"};
  comment = "#.*";
  multicom1 = "\"\"\"";
  multicom2 = "\"\"\"";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::javascript(){
  special =  { "import", "instanceof", "eval", "export", "if", "else", 
    "let", "class", "static", "using", "switch", "case", "throw", "interface",
    "catch", "try", "for", "while"
  };
  keywords = {"int", "char", "void", "function", "final", "public", 
    "private", "protected", "float", "long", "new", "return", "short", "extends",
    "this", "enum", "double", "do", "break", "continue", "byte", "typeof", "with"
  };
  comment = "//.*";
  multicom1 = "/*";
  multicom2 = "*/";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::c_sharp(){
  special =  { "using", "base", "explicit", "volatile", "if", "else", 
    "as", "class", "static", "using", "switch", "case", "throw", "interface",
    "catch", "try", "for", "while", "abstract"
  };
  keywords = {"int", "char", "void", "typeof", "string", "const", "public", 
    "private", "protected", "float", "long", "new", "return", "short", "namespace",
    "this", "enum", "double", "do", "break", "continue", "byte", "bool", "assert"
  };
  comment = "//.*";
  multicom1 = "/*";
  multicom2 = "*/";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}
