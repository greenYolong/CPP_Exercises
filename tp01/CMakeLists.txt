cmake_minimum_required(VERSION 3.17)
project(hello)

add_executable(hello
    ex1/main.cpp
)

target_compile_features(hello PUBLIC cxx_std_17)

target_compile_options(hello PRIVATE
    -Wall
    -Wextra
    -Werror
)