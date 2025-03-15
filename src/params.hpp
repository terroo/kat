#pragma once

#include <string>
#include <vector>

class Params {
  const std::string m_filetype;

  // langs
  void c_cpp();
  void java();
  void file_text();
  void python();
  void javascript();
  void c_sharp();
  void go_keys();
  void bash();
  void swift();

  public:
  Params(const std::string&);

  // all detectors
  inline static std::vector<std::string> special, keywords;
  inline static std::string comment, multicom1, 
         multicom2, fn1, fn2, str_newline,
         literal_str, args_fn, header_and_url;
};
