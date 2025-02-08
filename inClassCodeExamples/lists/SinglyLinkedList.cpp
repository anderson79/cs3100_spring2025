/**
 * SinglyLinkedList.cpp
 * This file contains the definition for the
 * SinglyLinkedList class
*/

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

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
    this->head = nullptr;
    this->tail = nullptr;

    SinglyLinkedNode* current = other.head;
    while (current != nullptr) {
        append(current->data);
        current = current->next;
    }
}

// destructor
// without this we had a memory leak
SinglyLinkedList::~SinglyLinkedList() {
    SinglyLinkedNode* current = head;
    while (current != nullptr) {
        SinglyLinkedNode* killMeNext = current->next;
        delete current; // release memory
        current = killMeNext;
    }
}

void SinglyLinkedList::append(string item) {
    SinglyLinkedNode* newNode = new SinglyLinkedNode(item);
    appendNode(newNode);
}

void SinglyLinkedList::appendNode(SinglyLinkedNode* node) {
    // list is empty
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    // list is not empty
    else {
        tail->next = node; // -> used to access member of a object as pointer
        //(*tail).next = node; // this does the same the previous line does
        tail = node;
    }
}

bool SinglyLinkedList::search(string item) {
    SinglyLinkedNode* current = head;
    // linked list traversal starts at the head
    // since tail->next is null, we continue
    // until current is null
    while (current != nullptr) {
        if (current->data == item) {
            // we found it! we can stop and return true
            return true;
        }
        // advance to the next node
        current = current->next;
    }
    // if we look through the entire list and didn't
    // return true above, we didn't find the item
    return false;
}

