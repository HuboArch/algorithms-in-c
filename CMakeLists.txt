cmake_minimum_required(VERSION 3.10)
project(algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(
        algorithms
        main.c
        data-structures/lists/headers/list.h
        data-structures/lists/sequential-list/sequential-list.c
        data-structures/lists/linked-list/one-way-linked-list.c
        data-structures/stacks/stack/header/stack.h
        data-structures/stacks/stack/stack.c
        data-structures/stacks/chain-stack/header/chain-stack.h
        data-structures/stacks/chain-stack/chain-stack.c
)