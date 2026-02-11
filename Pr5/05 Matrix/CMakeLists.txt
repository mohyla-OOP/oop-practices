cmake_minimum_required(VERSION 3.10.0)
project(Pr5Matrix VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(Pr5Matrix
    main.cpp
    Matrix.cpp
    CopyMatrix.cpp
    MoveMatrix.cpp
)
