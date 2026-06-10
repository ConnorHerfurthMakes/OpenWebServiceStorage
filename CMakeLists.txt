cmake_minimum_required(VERSION 3.10)

project(openwebstorage)

add_executable(openwebstorage main.cpp)

install(TARGETS openwebstorage RUNTIME DESTINATION bin)
