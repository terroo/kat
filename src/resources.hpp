#pragma once

#include <string>
#include <unordered_map>

constexpr auto unicode = [](const std::string& str){
  static const std::unordered_map<std::string, std::string> html = {
    {"cpp","\ufb71"},
    {"hpp","h"},
    {"c","\ufb70"},
    {"h","h"},
    {"java","\uf675"},
    {"py","\uf81f"},
    {"js","\ue74e"},
    {"ts","\ue628"},
    {"cs","\uf81a"},
    {"html","\uf13b"},
    {"md","\uf853"},
    {"css","\uf81b"},
    {"go","\ufcd1"},
    {"ter","\ufcb5"},
    {"swift","\ufbe3"},
    /*{"json","\ue60b"},
    {"yaml","\ue60b"},
    {"xml","\uf72d"},
    {"lua","\ue620"},
    {"s","\uf471"},
    {"asm","\uf471"},
    {"sh","\ufcb5"},
    {"ps1","\ufcb5"}*/
  }; // TODO: ruby, php, elixir, perl, zig, rust, erlang, haskell,...

  for(auto var : html){
    if(var.first == str){
      return var.second;
    }
  }

  return std::string{"\uf723"};
};
