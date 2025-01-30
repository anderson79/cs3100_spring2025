#include "SinglyLinkedList.h"   // you should only ever #include a .h file
                                // if your code doesn't work when you include the .h
                                // you likely have your C++ environment set up incorrectly
#include <iostream>

using namespace std;

int main() {
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

    return 0;
}