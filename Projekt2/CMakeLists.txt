cmake_minimum_required(VERSION 3.5)

project(Projekt2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -RELEASE")

add_executable(Projekt2 main.cpp Hearing_aid.cpp battery.cpp parameters.cpp electronic_device.cpp user.cpp phone.cpp smartphone.cpp)
