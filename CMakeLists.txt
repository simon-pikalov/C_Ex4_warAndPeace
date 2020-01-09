cmake_minimum_required(VERSION 3.15)
project(C_Ex3_warAndPeace C)

set(CMAKE_C_STANDARD 99)

add_executable(C_Ex3_warAndPeace cmake-build-debug/trie.c cmake-build-debug/trie.h cmake-build-debug/main.c)