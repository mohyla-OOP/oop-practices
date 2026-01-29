cmake_minimum_required(VERSION 3.28.0)
project(Pr3Module VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
add_executable(Pr3Module
    main.cpp
)
target_sources(Pr3Module
    PRIVATE
        FILE_SET CXX_MODULES
        FILES
            math.cppm
)

