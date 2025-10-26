#include "../include/AVLTree.h"
#include <iostream>
using namespace std;

AVLNode::AVLNode(const DomainRecord& record) {
    data = record;
    left = right = NULL;
    height = 1;
}

AVLTree::AVLTree() {
    root = NULL;
}

int AVLTree::heightOf(AVLNode* node) {
    if (!node) return 0;
    return node->height;
}

int AVLTree::balanceOf(AVLNode* node) {
    if (!node) return 0;
    return heightOf(node->left) - heightOf(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (heightOf(y->left) > heightOf(y->right) ? heightOf(y->left) : heightOf(y->right));
    x->height = 1 + (heightOf(x->left) > heightOf(x->right) ? heightOf(x->left) : heightOf(x->right));
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (heightOf(x->left) > heightOf(x->right) ? heightOf(x->left) : heightOf(x->right));
    y->height = 1 + (heightOf(y->left) > heightOf(y->right) ? heightOf(y->left) : heightOf(y->right));
    return y;
}

AVLNode* AVLTree::insertRec(AVLNode* node, const DomainRecord& record) {
    if (!node) return new AVLNode(record);

    if (record.domain < node->data.domain)
        node->left = insertRec(node->left, record);
    else if (record.domain > node->data.domain)
        node->right = insertRec(node->right, record);
    else
        return node;

    node->height = 1 + (heightOf(node->left) > heightOf(node->right) ? heightOf(node->left) : heightOf(node->right));

    int balance = balanceOf(node);

    if (balance > 1 && record.domain < node->left->data.domain)
        return rotateRight(node);
    if (balance < -1 && record.domain > node->right->data.domain)
        return rotateLeft(node);
    if (balance > 1 && record.domain > node->left->data.domain) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && record.domain < node->right->data.domain) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(const DomainRecord& record) {
    root = insertRec(root, record);
}

void AVLTree::inorder(AVLNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data.domain << " -> " << node->data.rule << endl;
    inorder(node->right);
}

void AVLTree::printInorder() {
    cout << "--- AVL Tree ---" << endl;
    inorder(root);
}
