cmake_minimum_required(VERSION 3.28)
project(hatch_generator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/generation.cpp
    src/parser.cpp
    src/generation.cpp
    src/out.cpp
)

set(HEADERS
    src/parser.h
    src/generation.h
    src/out.h
    src/struct.h
)

add_executable(hatch_generator ${SOURCES} ${HEADERS})

target_include_directories(hatch_generator PRIVATE  src)

target_compile_options(hatch_generator PRIVATE -Wall -Werror -Wextra)