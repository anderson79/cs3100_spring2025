#include "BSTree.h"

#include <iostream>

using namespace std;

void memLeak() {
    BSTree t;
    t.root = new BSTree::BSTNode(4);
    BSTree::BSTNode* leftChild = new BSTree::BSTNode(3);
    t.root->left = leftChild;
}

void testMemLeak() {
    cout << "Before" << endl;
    for (int i = 0; i < 100000; i++) {
        memLeak();
    }
    cout << "After" << endl;
}

void testInsert() {
    BSTree t;
    BSTree::BSTNode* nodeToInsert = new BSTree::BSTNode(50);
    t.InsertNode(nodeToInsert);

    t.InsertNode(new BSTree::BSTNode(26));
    t.InsertNode(new BSTree::BSTNode(19));
    t.InsertNode(new BSTree::BSTNode(21));
    t.InsertNode(new BSTree::BSTNode(19));

}

void recursiveFun(int num) {
    if (num == 0) {
        return;
    }

    cout << "Before recursive call: " << num << endl;
    recursiveFun(num - 1);
    cout << "After recursive call: " << num << endl;

}

void testInsertRef() {
    BSTree t;
    t.InsertNodeRef(t.root, 50);
    t.InsertNodeRef(t.root, 26);

}

int main() {
    //testInsert();
    //recursiveFun(5);
    testInsertRef();
    return 0;
}