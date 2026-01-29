cmake_minimum_required(VERSION 3.10.0)
project(Pr3OfficeBigger VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "cxx")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
add_executable(Pr3OfficeBigger
    main.cpp
    Office.cpp
)

target_sources(Pr3OfficeBigger
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            Office.ixx
)

