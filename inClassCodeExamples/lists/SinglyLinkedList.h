//
// SinglyLinkedList.h
// This is the header file for our SinglyLinkedList
// It contains the declaration for both SinglyLinkedNode
// and SinglyLinkedList
// You will #include "SinglyLinkedList.h" to use it
//

// CLion will automatically generate these for you
// your code goes in between this and the #endif at the bottom of the file
// you only need this in the .h file
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>

using namespace std; // dont have to say std::

class SinglyLinkedNode {
public: // everthing after this will be public
    string data;
    SinglyLinkedNode* next;

    // parameterized constructor
    // because I have a parameterized constructor, the only way to create
    // a node is to pass in a string for the data
    SinglyLinkedNode(string initData) {
        data = initData;
        next = nullptr;
    }
};

class SinglyLinkedList {
private: // everything after this and before public: below will be private
        // eventually I should put stuff here I don't want users to access
        // but for now it's easier to make things public

public:
    SinglyLinkedNode* head;
    SinglyLinkedNode* tail;

    // default constructor for SinglyLinkedList
    // this is called the declaration, saying to the compiler I am going to
    // write my own default constructor
    // the definition for it is in SinglyLinkedList.cpp
    SinglyLinkedList();


}; //remember semicolon

#endif //SINGLYLINKEDLIST_H
