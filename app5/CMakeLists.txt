cmake_minimum_required(VERSION 3.18)
project(hellogtk LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

add_executable(hellogtk hello.cc)
target_link_libraries(hellogtk PRIVATE PkgConfig::GTKMM)
target_compile_features(hellogtk PRIVATE cxx_std_17)