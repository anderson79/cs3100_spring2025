cmake_minimum_required(VERSION 3.30)
project(lists)

set(CMAKE_CXX_STANDARD 20)

add_executable(linkedListTests linkedListTests.cpp
        SinglyLinkedList.cpp
        SinglyLinkedList.h
        ArrayList.cpp
        ArrayList.h
)

add_executable(arrayListTests ArrayList.cpp ArrayList.h
        arrayListTests.cpp)
