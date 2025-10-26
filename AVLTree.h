#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "DomainRecord.h"
#include <string>
using namespace std;

class AVLNode {
public:
    DomainRecord data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(const DomainRecord& record);
};

class AVLTree {
private:
    AVLNode* root;
    int heightOf(AVLNode* node);
    int balanceOf(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* insertRec(AVLNode* node, const DomainRecord& record);
    void inorder(AVLNode* node);

public:
    AVLTree();
    void insert(const DomainRecord& record);
    void printInorder();
};

#endif
