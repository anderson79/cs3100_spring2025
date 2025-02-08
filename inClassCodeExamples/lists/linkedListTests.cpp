/**
 * linkedListTests.cpp
 * demo and testing for SinglyLinkedList
 */
#include "SinglyLinkedList.h"   // you should only ever #include a .h file
                                // if your code doesn't work when you include the .h
                                // you likely have your C++ environment set up incorrectly
#include <iostream>

using namespace std;

void foo() {
    SinglyLinkedNode n("james");
    n.next = new SinglyLinkedNode("tom");
    cout << n.data;
    delete n.next;
}

void copyList(SinglyLinkedList list) {
    list.append("appened in copyList");
}

void refList(SinglyLinkedList& list) {
    list.append("appended in refList");
}

int main() {
    int i = 7;
    foo();

    // Create a variable of type SinglyLinkedNode
    // In this case, node is an actual SinglyLinkedNode object
    // and not a reference/pointer to an object
    // Since it's a value, I can say
    // Type v(params)
    // Instead of
    // Type v = Type(params)
    SinglyLinkedNode node("node");

    // Similar to node, list is a list object
    // not a referece/pointer to a list
    // The data for both node and list is located on the
    // --- run-time stack ---
    // and are local variables for the main function
    SinglyLinkedList list;

    SinglyLinkedNode* myNode = new SinglyLinkedNode("myNode");
    list.appendNode(myNode);

    SinglyLinkedNode* myNode2 = new SinglyLinkedNode("myNode2");
    list.appendNode(myNode2);

    myNode2 = new SinglyLinkedNode("myNode3");
    list.appendNode(myNode2);

    list.append("james");

    for (int i = 0; i < 100000; i++) {
        copyList(list);
    }
    return 0;
}