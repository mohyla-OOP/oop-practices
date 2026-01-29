cmake_minimum_required(VERSION 3.10.0)
project(Pr3Office VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(Pr3Office
    main.cpp
    Accountant.cpp
    Employee.cpp
    Employer.cpp
    Person.cpp
    Position.cpp
)

