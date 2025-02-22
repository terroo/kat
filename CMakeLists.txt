cmake_minimum_required(VERSION 3.10)
project(MyProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")

find_package(Boost REQUIRED COMPONENTS regex)

add_executable(kat 
  ${CMAKE_SOURCE_DIR}/src/main.cpp 
  ${CMAKE_SOURCE_DIR}/src/kat.cpp 
  ${CMAKE_SOURCE_DIR}/src/params.cpp
)

target_link_libraries(kat PRIVATE Boost::regex)

install(TARGETS kat DESTINATION bin)
