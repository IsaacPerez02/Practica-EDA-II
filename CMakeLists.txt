cmake_minimum_required(VERSION 3.24)
project(untitled4 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled4 sources/main.c headers/user.h sources/user.c headers/user_list.h sources/user_list.c)
