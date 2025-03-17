#include "BSTree.h"

#include <iostream>

using namespace std;

void memLeak() {
    BSTree t;
    t.root = new BSTree::BSTNode(4);
    BSTree::BSTNode* leftChild = new BSTree::BSTNode(3);
    t.root->left = leftChild;
}

int main() {
    BSTree tree;

    tree.root = new BSTree::BSTNode(7);

    BSTree::BSTNode* leftChild = new BSTree::BSTNode(3);

    tree.root->left = leftChild;

    cout << "Before" << endl;
    for (int i = 0; i < 100000; i++) {
        memLeak();
    }
    cout << "After" << endl;
    return 0;
}