#include <iostream>
#include "./src/AVL.h"

int main() {
    AVLTree<int,int> tree = {};
    tree.insert(3,65);

    std::cout << (tree.root->key == 3? "True" : "False") << std::endl;

    tree.insert(2,66);

    std::cout << (tree.root->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 2? "True" : "False") << std::endl;

    tree.insert(1,67);

    std::cout << (tree.root->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 3? "True" : "False") << std::endl;

    tree.insert(4,68);

    std::cout << (tree.root->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 4? "True" : "False") << std::endl;

    tree.insert(5,69);

    std::cout << (tree.root->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 5? "True" : "False") << std::endl;

    tree.insert(6,70);

    std::cout << (tree.root->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 6? "True" : "False") << std::endl;

    tree.insert(7,71);

    std::cout << (tree.root->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 7? "True" : "False") << std::endl;

    tree.insert(16,72);

    std::cout << (tree.root->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->right->key == 16? "True" : "False") << std::endl;

    tree.insert(15,73);

    std::cout << (tree.root->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 15? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->left->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->right->key == 16? "True" : "False") << std::endl;

    tree.insert(14,74);

    std::cout << (tree.root->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 15? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->left->key == 14? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->right->key == 16? "True" : "False") << std::endl;

    tree.insert(13,75);

    std::cout << (tree.root->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 15? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 14? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 16? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->left->key == 13? "True" : "False") << std::endl;

    tree.insert(12,76);

    std::cout << (tree.root->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 15? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 13? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 16? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->left->key == 12? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->right->key == 14? "True" : "False") << std::endl;

    tree.insert(11,77);

    std::cout << (tree.root->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 13? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 12? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 15? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->left->key == 11? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->left->key == 14? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->right->key == 16? "True" : "False") << std::endl;

    tree.insert(10,78);

    std::cout << (tree.root->key == 7? "True" : "False") << std::endl;
    std::cout << (tree.root->left->key == 4? "True" : "False") << std::endl;
    std::cout << (tree.root->right->key == 13? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->key == 2? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->key == 6? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->key == 11? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->key == 15? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->left->key == 1? "True" : "False") << std::endl;
    std::cout << (tree.root->left->left->right->key == 3? "True" : "False") << std::endl;
    std::cout << (tree.root->left->right->left->key == 5? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->left->key == 10? "True" : "False") << std::endl;
    std::cout << (tree.root->right->left->right->key == 12? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->left->key == 14? "True" : "False") << std::endl;
    std::cout << (tree.root->right->right->right->key == 16? "True" : "False") << std::endl;

    std::cout << "OK" << std::endl;
    return 0;
}
