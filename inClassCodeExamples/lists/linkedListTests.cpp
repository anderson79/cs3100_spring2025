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
    cout << n.data << endl;
    delete n.next;
}

void copyList(SinglyLinkedList list) {
    list.append("appeneded in copyList");
    cout << "In copyList, list: " << list.toString() << endl;
}

void refList(SinglyLinkedList& list) {
    list.append("appended in refList");
}

void testCopyConstructor() {
    cout << "Testing copy constructor" << endl;
    SinglyLinkedList list;
    list.append("appended in copyConstructor");
    copyList(list);
    cout << "After copyList, original list: " << list.toString() << endl << endl;

}

void testAssignmentOperator() {
    cout << "Testing assignment operator" << endl;
    SinglyLinkedList list1;
    list1.append("appending");
    list1.append("to");
    list1.append("list1");
    SinglyLinkedList list2;
    list2.append("now appending to list 2");

    list1 = list2;
    list1.append("appending back to list 1");
    list2.append("appending more to list 2");

    cout << "After assigning list1 to list2 and appending something to each: " << endl;
    cout << "list1: " << list1.toString() << endl;
    cout << "list2: " << list2.toString() << endl << endl;
}

/**
 * to test the destructor, you want to use Task Manager on Windows
 * or Activity Monitor on MacOS. You can search in those windows
 * if you're using CLion, the name of the exe is the named what you
 * have selected in the drop-down next to the Build/Run/Debug
 * buttons in the upper-right (for this it would be "linkedListTests"
 */
void testDestructor() {
    cout << "Testing destructor" << endl;
    cout << "Before memory leak test...";
    // put a break point on the next line, debug program
    // check memory usage before the test
    cout << endl;
    for (int i = 0; i < 1000000; i++) {
        SinglyLinkedList list;
        list.append("appending");
        list.append("to");
        list.append("test");
        list.append("destructor");
    }
    cout << "After memory leak test...";
    // put a break point on the next line
    // when the leak test loop finishes, see if the amount of memory your
    // program is using went up by a lot
    cout << endl;
}

void linkedListTests() {
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

    cout << list << endl;

    string itemToFind = "myNode2";
    SinglyLinkedNode* searchedNode = list.searchNode(itemToFind);
    if (searchedNode == nullptr) {
        cout << "No node with " << itemToFind << endl;
    } else {
        cout << "found node: " << searchedNode->data << endl;
    }

}

int main() {
    testCopyConstructor();
    testAssignmentOperator();
    testDestructor();

    return 0;
}