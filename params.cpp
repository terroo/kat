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
  }else if(m_filetype == "go"){
    go_keys();
  }else if(m_filetype == "ter"){
    c_cpp();
  }else if(m_filetype == "sh" || m_filetype == "bash"){
    bash();
  }else if(m_filetype == "swift"){
    swift();
  }else if(m_filetype == "rs"){
    rust();
  }else if(m_filetype == "my"){
    my();
  }else if(m_filetype == "sql"){
    sql();
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

// base
void Params::c_sharp(){
  special =  { "using", "base", "explicit", "volatile", "if", "else", 
    "as", "class", "static", "using", "switch", "case", "throw", "interface",
    "catch", "try", "for", "while", "abstract"
  };
  keywords = {"int", "char", "void", "typeof", "string", "const", "public", "var",
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


// base
void Params::go_keys(){
  special =  { "package", "fmt", "default", "map", "if", "else", 
    "import", "struct", "select", "switch", "case", "interface",
    "chan", "type", "for", "while", "var"
  };
  keywords = {"int", "char", "void", "printf", "string", "const", "public", 
    "float", "return", "short", "func", "rune", "enum", "double", "do", 
    "break", "continue", "byte", "bool", "goto"
  };
  comment = "//.*";
  multicom1 = "#";
  multicom2 = "$";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::bash(){
  special =  { "source", "if", "else", "elif", "fi",
    "case", "esac", "echo", "select", "until", 
    "for", "time", "while"
  };
  keywords = {"printf", "return", "do", "break", "continue", "declare", "shift", "readonly"};
  comment = "#.*$";
  multicom1 = "#!";
  multicom2 = " ";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::swift(){
  special =  { "class", "struct", "enum", "protocol", "if", "else", 
    "typealias", "associatedtype", "import", "switch", "case", "let",
    "init", "deinit", "for", "while", "var", "is", "as"
  };
  keywords = {"Int", "Character", "throws", "print", "String", "final", "public", 
    "Float", "return", "async", "await", "func", "catch", "super", "Double", "do", 
    "break", "continue", "try", "Bool", "default", "private"
  };
  comment = "//.*";
  multicom1 = "#";
  multicom2 = "$";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::rust(){
  special =  { "impl", "struct", "enum", "pub", "if", "else", 
    "typealias", "fn", "import", "switch", "case", "let",
    "init", "deinit", "for", "while", "var", "is", "as"
  };
  keywords = {"int", "char", "mut", "println", "string", "final", "public", 
    "float", "return", "async", "await", "func", "catch", "super", "double", "do", 
    "break", "continue", "try", "bool", "default", "private", "const"
  };
  comment = "//.*";
  multicom1 = "#";
  multicom2 = "$";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::my(){
  special =  {"class", "fun", "return", "if", "else", "while", "for"};
  keywords = {"var", "print"};
  comment = "//.*";
  multicom1 = "@@@@";
  multicom2 = "@@@@@";
  fn1 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  fn2 = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*(?=\\,|\\))";
  header_and_url = "<[^>]+>";
}

void Params::sql(){
    special = {
    "JOIN", "join", "SELECT", "select", "FROM", "from", "WHERE", "where",
    "INNER JOIN", "inner join", "LEFT JOIN", "left join", "RIGHT JOIN", "right join", 
    "FULL JOIN", "full join", "CROSS JOIN", "cross join", "NATURAL JOIN", "natural join",
    "GROUP BY", "group by", "ORDER BY", "order by", "HAVING", "having", "LIMIT", "limit",
    "COUNT", "count", "SUM", "sum", "AVG", "avg", "MIN", "min", 
    "MAX", "max", "NOW", "now", "UPPER", "upper", "LOWER", "lower", "LENGTH", "length", "DESC", "desc", "ASC", "asc", "IN", "in"
  };

  keywords = {"BEGIN","begin","COMMIT","commit","ROLLBACK",
    "rollback","SAVEPOINT","savepoint","RELEASE","release",
    "SET TRANSACTION","set transaction", "AND", "and", "OR", "or", "NOT", "not", "LIKE", "like", 
    "BETWEEN", "between", "IS", "is", "NULL", "null", 
};

  comment = "--.*";
  multicom1 = "/*";
  multicom2 = "*/";
  fn1 = "@@@@";
  fn2 = "@@@@";
  str_newline = "\\\\n";
  literal_str = "\".*?\"";
  args_fn = "@@@@";
  header_and_url = "@@@@";
}