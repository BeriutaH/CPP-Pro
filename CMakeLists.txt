cmake_minimum_required(VERSION 3.27)
project(CppNew)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppNew main.cpp
        user.h
        func.h
        apps/my_str/projects.h
        apps/my_str/projects.cpp
        apps/pch/pch.h
        apps/calculator/calculator.cpp
        apps/calculator/calculator.h
        apps/pub/drinks.cpp
        apps/pub/drinks.h
)

target_precompile_headers(CppNew PRIVATE apps/pch/pch.h)
target_include_directories(CppNew PRIVATE apps)
