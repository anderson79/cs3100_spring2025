//
// Created by drink on 1/29/2025.
//

#include "SinglyLinkedList.h"

// definition of SinglyLinkedList default constructor
// head and tail aren't guaranteed to be null when
// I create a list, so I want to make sure they will be
// the syntax for defining a method is
// ClassName::methodName
// So the compiler knows we are defining a method that we
// declared in the .h file
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

