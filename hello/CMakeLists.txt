cmake_minimum_required(VERSION 3.18)
project(hellogtk LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(hellogtk hello.c)
target_link_libraries(hellogtk PRIVATE PkgConfig::GTK4)