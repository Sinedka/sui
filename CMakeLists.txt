cmake_minimum_required(VERSION 3.10)
project(HelloCMake ASM_NASM CXX)

set(CMAKE_CXX_STANDARD 20)

# включаем clang-tidy
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")

# экспортируем compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
    )
endif()

# ассемблер
enable_language(ASM_NASM)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)

# сборка
add_executable(hello test/replacement.asm src/mylib.cpp)

target_include_directories(hello PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
