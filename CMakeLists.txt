cmake_minimum_required(VERSION 3.10)

project(ShellProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include the header directory so that our sources can find the header files.
include_directories(header)

# List all the source files.
set(SOURCES
    src/main.c
    src/sh_init.c
    src/sh_inter.c
    src/sh_term.c
    sh_inter.c
)

# Create the executable target.
add_executable(shell ${SOURCES})
