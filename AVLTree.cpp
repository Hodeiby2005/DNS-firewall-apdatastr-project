#include "../include/AVLTree.h"
#include <iostream>
using namespace std;

// Constructor for AVLNode - creates a new node with the given DomainRecord
AVLNode::AVLNode(const DomainRecord& record) {
    data = record;
    left = right = NULL;
    height = 1;
}

// Constructor for AVLTree - creates an empty tree
AVLTree::AVLTree() {
    root = NULL;
}

// Returns the height of a given node (handles null case)
int AVLTree::heightOf(AVLNode* node) {
    if (!node) return 0;
    return node->height;
}

// Calculates the balance factor of a node (difference between left and right subtree heights)
int AVLTree::balanceOf(AVLNode* node) {
    if (!node) return 0;
    return heightOf(node->left) - heightOf(node->right);
}

// Performs a right rotation around the given node (y)
// Used when left subtree is heavier and left child's left subtree causes imbalance
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (heightOf(y->left) > heightOf(y->right) ? heightOf(y->left) : heightOf(y->right));
    x->height = 1 + (heightOf(x->left) > heightOf(x->right) ? heightOf(x->left) : heightOf(x->right));
    return x;
}

// Performs a left rotation around the given node (x)
// Used when right subtree is heavier and right child's right subtree causes imbalance
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (heightOf(x->left) > heightOf(x->right) ? heightOf(x->left) : heightOf(x->right));
    y->height = 1 + (heightOf(y->left) > heightOf(y->right) ? heightOf(y->left) : heightOf(y->right));
    return y;
}

// Recursive helper function to insert a new record into the AVL tree
// Handles BST insertion and maintains AVL balance through rotations
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

    // Left Left Case - single right rotation
    if (balance > 1 && record.domain < node->left->data.domain)
        return rotateRight(node);
    
    // Right Right Case - single left rotation
    if (balance < -1 && record.domain > node->right->data.domain)
        return rotateLeft(node);
    
    // Left Right Case - left rotation then right rotation
    if (balance > 1 && record.domain > node->left->data.domain) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    // Right Left Case - right rotation then left rotation
    if (balance < -1 && record.domain < node->right->data.domain) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Public interface to insert a new record into the AVL tree
void AVLTree::insert(const DomainRecord& record) {
    root = insertRec(root, record);
}

// Recursive helper function to perform inorder traversal
// Prints domains and rules in sorted order
void AVLTree::inorder(AVLNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data.domain << " -> " << node->data.rule << endl;
    inorder(node->right);
}

// Public interface to print the entire AVL tree in sorted order
void AVLTree::printInorder() {
    cout << "--- AVL Tree ---" << endl;
    inorder(root);
}
