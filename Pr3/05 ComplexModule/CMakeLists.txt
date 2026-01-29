cmake_minimum_required(VERSION 3.10.0)
project(Pr3ComplexModule VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "cxx")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
add_executable(Pr3ComplexModule
    main.cpp
    Complex.cpp
)

target_sources(Pr3ComplexModule
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            Complex.ixx
)

