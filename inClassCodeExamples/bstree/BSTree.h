//
// Created by drink on 3/17/2025.
//

#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <ostream>

class BSTree {
    public:
    class BSTNode {
        public:
        int key;
        BSTNode* left;
        BSTNode* right;

        int height;

        BSTNode(int k) : key(k), left(nullptr), right(nullptr), height(0) {
            //key = k;
        }

        int leftHeight() {
            if (left != nullptr) {
                return left->height;
            }
            return -1;
        }
    };

    BSTNode* root;

    BSTree() : root(nullptr)
    {}

    ~BSTree() {
        delete root;
    }

    void InsertNode(BSTNode* node) {
        if (root == nullptr) {
            this->root = node;
        }
        else {
            //InsertNodeRecursive(root, node);
            InsertNodeRef(root, node->key);
        }
    }

    void InsertNodeRef(BSTNode*& node, int key) {
        if (node == nullptr) {
            node = new BSTNode(key);
            return;
        }
        if (key == node->key) {
            return;
        }
        if (key < node->key) {
            InsertNodeRef(node->left, key);
        } else if (key > node->key) {
            InsertNodeRef(node->right, key);
        }
        node = node->left;
    }

    void InsertNodeRecursive(BSTNode* parent, BSTNode* nodeToInsert) {
        if (nodeToInsert->key < parent->key) {
            if (parent->left == nullptr) {
                parent->left = nodeToInsert;
            }
            else {
                InsertNodeRecursive(parent->left, nodeToInsert);
                std::cout << "Done with parent->left" << std::endl;
            }
        }
        else if (nodeToInsert->key > parent->key) {
            if (parent->right == nullptr) {
                parent->right = nodeToInsert;
            }
            else {
                InsertNodeRecursive(parent->right, nodeToInsert);
                std::cout << "Done with parent->right" << std::endl;
            }
        }
        //check parent height
    }
};



#endif //BSTREE_H
