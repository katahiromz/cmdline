# CMakeLists.txt --- CMake project settings
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# project name and language
project(cmdline C)

# cmdline.exe
add_executable(cmdline cmdline.c)

if(WIN32)
    # wcmdline.exe
    add_executable(wcmdline wcmdline.c)
    target_compile_definitions(wcmdline PRIVATE UNICODE _UNICODE)
endif()
