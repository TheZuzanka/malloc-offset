cmake_minimum_required(VERSION 3.9)
project(DSA_1_projekt_offset C)

set(CMAKE_C_STANDARD 99)

add_executable(DSA_1_projekt_offset main.c memory_init.c header.h main.h memory_check.c extra_functions.c memory_alloc.c memory_free.c)