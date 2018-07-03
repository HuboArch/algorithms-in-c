cmake_minimum_required(VERSION 3.10)
project(algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(
        algorithms
        main.c
        data-structures/lists/linked-list/singly-linked-list/header/singly-linked-list.h
        data-structures/lists/linked-list/singly-linked-list/singly-linked-list.c
        data-structures/stack/header/stack.h data-structures/stack/stack.c)