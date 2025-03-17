//
// Created by drink on 3/17/2025.
//

#ifndef BSTREE_H
#define BSTREE_H

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



    bool insertKey(int k) {

    }
};



#endif //BSTREE_H
