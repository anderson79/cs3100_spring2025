cmake_minimum_required(VERSION 3.30)
project(lists)

set(CMAKE_CXX_STANDARD 20)

add_executable(lists main.cpp
        SinglyLinkedList.cpp
        SinglyLinkedList.h)
