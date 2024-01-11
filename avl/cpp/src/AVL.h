#ifndef AVL_H
#define AVL_H

template<typename K, typename V>
class AVLNode {
public:
    K key;
    V value;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(K key, V value);
    ~AVLNode();
};

template<typename K, typename V>
class AVLTree {
public:
    AVLNode<K, V>* root;

    AVLTree();
    ~AVLTree();

    AVLNode<K, V>* rotateRight(AVLNode<K, V>* y);

    AVLNode<K, V>* rotateLeft(AVLNode<K, V>* x);

    AVLNode<K, V>* _insert(AVLNode<K, V>* root, int key, int value);

    void insert(int key, int value);
};

#include "AVL.hpp"

#endif //AVL_H
