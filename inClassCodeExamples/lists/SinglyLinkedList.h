/**
*
* SinglyLinkedList.h
* This is the header file for our SinglyLinkedList
* It contains the declaration for both SinglyLinkedNode
* and SinglyLinkedList
* You will #include "SinglyLinkedList.h" to use it
*
*/


// CLion will automatically generate these for you
// your code goes in between this and the #endif at the bottom of the file
// you only need this in the .h file
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <string>

using namespace std; // dont have to say std::

class SinglyLinkedNode {
public: // everything after this will be public
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

    // copy constructor
    SinglyLinkedList(const SinglyLinkedList& other);

    // assignment operator
    void operator=(const SinglyLinkedList& other);

    // destructor
    ~SinglyLinkedList();

    // append adds the item to the end of the list
    void append(string item);
    // appendNode adds the node to the end of the list
    // for the List ADT, there is no concept of a node
    // ideally this could be private, but for our example
    void appendNode(SinglyLinkedNode* node);

    bool search(string item) const;
    SinglyLinkedNode* searchNode(string item) const;


    // helper method so we can get a string of the whole list
    string toString() const;
}; //remember semicolon

// overload of << so we can output to cout
ostream& operator<<(ostream& os, const SinglyLinkedList& list);

#endif //SINGLYLINKEDLIST_H
