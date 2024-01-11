#include "AVL.h"
#include <iostream>
#include <algorithm>

using std::max;

template<typename K, typename V>
AVLNode<K, V>::AVLNode(K key, V value)
    : key(key), value(value), height(1), left(nullptr), right(nullptr) {}

template<typename K, typename V>
AVLNode<K, V>::~AVLNode()  {
    delete left;
    delete right;
}

template<typename K, typename V>
int height_of(AVLNode<K, V>* node) {
    return (node == nullptr) ? 0 : node->height;
}

template<typename K, typename V>
int balance_of(AVLNode<K, V>* node) {
    return (node == nullptr) ? 0 : height_of(node->left) - height_of(node->right);
}



template<typename K, typename V>
AVLTree<K, V>::AVLTree() : root(nullptr) {}

template<typename K, typename V>
AVLTree<K, V>::~AVLTree() { delete root; }

template<typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::rotateRight(AVLNode<K, V> *y)  {
    AVLNode<K, V>* x = y->left;
    AVLNode<K, V>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height_of(y->left), height_of(y->right));
    x->height = 1 + max(height_of(x->left), height_of(x->right));

    return x;
}

template<typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::rotateLeft(AVLNode<K, V> *x)  {
    AVLNode<K, V>* y = x->right;
    AVLNode<K, V>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height_of(x->left), height_of(x->right));
    y->height = 1 + max(height_of(y->left), height_of(y->right));

    return y;
}

template<typename K, typename V>
AVLNode<K, V> *AVLTree<K, V>::_insert(AVLNode<K, V> *root, int key, int value)  {
    if (root == nullptr)
        return new AVLNode(key, value);

    if (key < root->key)
        root->left = _insert(root->left, key, value);
    else if (key > root->key)
        root->right = _insert(root->right, key, value);
    else {
        root->value = value;
        return root;
    }

    root->height = 1 + max(height_of(root->left), height_of(root->right));

    const int balance = balance_of(root);

    // Left-Left Case
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Right-Right Case
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // Left-Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right-Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

template<typename K, typename V>
void AVLTree<K, V>::insert(int key, int value)  {
    root = _insert(root, key, value);
}