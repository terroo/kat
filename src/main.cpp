#include "kat.hpp"

int main(int argc, char **argv){

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [file]" << std::endl;
    return EXIT_FAILURE;
  }

  if(isatty(STDOUT_FILENO)){
    auto kat = std::make_unique<Kat>(argv[1], 0);
    kat->print_code();
  }else{
    auto kat = std::make_unique<Kat>(argv[1], 1);
    kat->print_code();
  }

  return EXIT_SUCCESS;
}
