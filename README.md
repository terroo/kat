# kat `command`
> A `cat` command with **syntax highlight**.

![kat](./kat.png) 
> A `cat` command that almost tastes like **chocolate**!

---

## Dependencies
+ C++ Compiler: [GNU GCC](https://gcc.gnu.org/) or [Clang LLVM](https://clang.llvm.org/)
+ [Boost.Regex](https://www.boost.org/doc/libs/1_87_0/libs/regex/)
+ [CMake](https://cmake.org/)

Example on Ubuntu:
```bash
sudo apt update
sudo apt install build-essential cmake libboost-regex-dev
```

---

## Install
```bash
git clone http://github.com/terroo/kat build-kat
cd build-kat
cmake -B build .
cmake --build build
sudo cmake --install build
```

---

## Usage
> Examples
```bash
kat main.cpp # C++ file
kat main.c # C file
kat MyClass.java # Java file
kat script.py # Python file
kat index.js # JavaScript file
kat Main.cs # C# file
kat file.txt # Text file
kat --help
```

---

## Note
> This repository is still under development and does not yet support all languages and file types. If you want us to speed up the implementation of your language/file, please notify us in [issues](https://github.com/terroo/kat/issues)
