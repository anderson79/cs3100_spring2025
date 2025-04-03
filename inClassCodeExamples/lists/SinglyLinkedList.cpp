/**
 * SinglyLinkedList.cpp
 * This file contains the definition for the
 * SinglyLinkedList class
*/

#include "SinglyLinkedList.h"

#include <iostream>

#include "ArrayList.h"

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

void SinglyLinkedList::operator=(const SinglyLinkedList& other) {
    // first I would need to destroy "this" list
    // can use same code in destructor
    // since I use this code in two places I could probably make
    // a helper method to do this stuff
    SinglyLinkedNode* current = head;
    while (current != nullptr) {
        SinglyLinkedNode* killMeNext = current->next;
        delete current; // release memory
        current = killMeNext;
    }

    // next copy the contents of "other" into "this" list
    // can use same code as copy constructor
    // since I use this code in two places I could probably make
    // a helper method... wait I already said this
    this->head = nullptr;
    this->tail = nullptr;

    current = other.head;
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

bool SinglyLinkedList::search(string item) const {
    return searchNode(item) != nullptr;
}

SinglyLinkedNode* SinglyLinkedList::searchNode(string item) const {
    SinglyLinkedNode* current = head;
    // linked list traversal starts at the head
    // since tail->next is null, we continue
    // until current is null
    while (current != nullptr) {
        if (current->data == item) {
            // we found it! we can stop and return current pointer
            return current;
        }
        // advance to the next node
        current = current->next;
    }
    // if we look through the entire list and didn't
    // return above, we didn't find the item
    return nullptr;
}

string SinglyLinkedList::toString() const {
    SinglyLinkedNode* current = head;
    string result;
    while (current != nullptr) {
        result += current->data;
        if (current->next != nullptr) {
            result += ", ";
        }
        current = current->next;
    }
    return result;
}

ostream& operator<<(ostream& os, const SinglyLinkedList& list) {
    os << list.toString();
    return os;
}

