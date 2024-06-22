cmake_minimum_required(VERSION 3.28)
project(ext_rayaop C)

set(CMAKE_C_STANDARD 11)

add_library(ext_rayaop STATIC library.c)
