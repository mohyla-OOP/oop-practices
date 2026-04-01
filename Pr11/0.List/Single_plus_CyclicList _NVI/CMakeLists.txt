cmake_minimum_required(VERSION 3.10.0)
project(
  Pr11Single_plus_CyclicList_NVI
  VERSION 0.1.0
  LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(Pr11Single_plus_CyclicList_NVI main.cpp ImpList.cpp)
