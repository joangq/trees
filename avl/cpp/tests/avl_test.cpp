#include "gtest-1.8.1/gtest.h"
#include "../src/AVL.h"

class AVLTest : public testing::Test {
protected:
    AVLTree<int, int> tree;

    void SetUp() override {
        tree = {};
    }
};

TEST_F(AVLTest, inserciones) {
    tree.insert(3, 65);

    ASSERT_EQ(tree.root->key, 3);

    tree.insert(2, 66);

    ASSERT_EQ(tree.root->key, 3);
    ASSERT_EQ(tree.root->left->key, 2);

    tree.insert(1, 67);

    ASSERT_EQ(tree.root->key, 2);
    ASSERT_EQ(tree.root->left->key, 1);
    ASSERT_EQ(tree.root->right->key, 3);

    tree.insert(4, 68);

    ASSERT_EQ(tree.root->key, 2);
    ASSERT_EQ(tree.root->left->key, 1);
    ASSERT_EQ(tree.root->right->key, 3);
    ASSERT_EQ(tree.root->right->right->key, 4);

    tree.insert(5, 69);

    ASSERT_EQ(tree.root->key, 2);
    ASSERT_EQ(tree.root->left->key, 1);
    ASSERT_EQ(tree.root->right->key, 4);
    ASSERT_EQ(tree.root->right->left->key, 3);
    ASSERT_EQ(tree.root->right->right->key, 5);

    tree.insert(6, 70);

    ASSERT_EQ(tree.root->key, 4);
    ASSERT_EQ(tree.root->left->key, 2);
    ASSERT_EQ(tree.root->right->key, 5);
    ASSERT_EQ(tree.root->left->left->key, 1);
    ASSERT_EQ(tree.root->left->right->key, 3);
    ASSERT_EQ(tree.root->right->right->key, 6);

    tree.insert(7, 71);

    ASSERT_EQ(tree.root->key, 4);
    ASSERT_EQ(tree.root->left->key, 2);
    ASSERT_EQ(tree.root->right->key, 6);
    ASSERT_EQ(tree.root->left->left->key, 1);
    ASSERT_EQ(tree.root->left->right->key, 3);
    ASSERT_EQ(tree.root->right->left->key, 5);
    ASSERT_EQ(tree.root->right->right->key, 7);

    tree.insert(16, 72);

    ASSERT_EQ(tree.root->key, 4);
    ASSERT_EQ(tree.root->left->key, 2);
    ASSERT_EQ(tree.root->right->key, 6);
    ASSERT_EQ(tree.root->left->left->key, 1);
    ASSERT_EQ(tree.root->left->right->key, 3);
    ASSERT_EQ(tree.root->right->left->key, 5);
    ASSERT_EQ(tree.root->right->right->key, 7);
    ASSERT_EQ(tree.root->right->right->right->key, 16);

    tree.insert(15, 73);

    ASSERT_EQ(tree.root->key, 4);
    ASSERT_EQ(tree.root->left->key, 2);
    ASSERT_EQ(tree.root->right->key, 6);
    ASSERT_EQ(tree.root->left->left->key, 1);
    ASSERT_EQ(tree.root->left->right->key, 3);
    ASSERT_EQ(tree.root->right->left->key, 5);
    ASSERT_EQ(tree.root->right->right->key, 15);
    ASSERT_EQ(tree.root->right->right->left->key, 7);
    ASSERT_EQ(tree.root->right->right->right->key, 16);

    tree.insert(14, 74);

    ASSERT_EQ(tree.root->key, 4);
    ASSERT_EQ(tree.root->left->key, 2);
    ASSERT_EQ(tree.root->right->key, 7);
    ASSERT_EQ(tree.root->left->left->key, 1);
    ASSERT_EQ(tree.root->left->right->key, 3);
    ASSERT_EQ(tree.root->right->left->key, 6);
    ASSERT_EQ(tree.root->right->left->left->key, 5);
    ASSERT_EQ(tree.root->right->right->key, 15);
    ASSERT_EQ(tree.root->right->right->left->key, 14);
    ASSERT_EQ(tree.root->right->right->right->key, 16);

    tree.insert(13, 75);

    ASSERT_EQ(tree.root->key, 7);
    ASSERT_EQ(tree.root->left->key, 4);
    ASSERT_EQ(tree.root->right->key, 15);
    ASSERT_EQ(tree.root->left->left->key, 2);
    ASSERT_EQ(tree.root->left->right->key, 6);
    ASSERT_EQ(tree.root->right->left->key, 14);
    ASSERT_EQ(tree.root->right->right->key, 16);
    ASSERT_EQ(tree.root->left->left->left->key, 1);
    ASSERT_EQ(tree.root->left->left->right->key, 3);
    ASSERT_EQ(tree.root->left->right->left->key, 5);
    ASSERT_EQ(tree.root->right->left->left->key, 13);

    tree.insert(12, 76);

    ASSERT_EQ(tree.root->key, 7);
    ASSERT_EQ(tree.root->left->key, 4);
    ASSERT_EQ(tree.root->right->key, 15);
    ASSERT_EQ(tree.root->left->left->key, 2);
    ASSERT_EQ(tree.root->left->right->key, 6);
    ASSERT_EQ(tree.root->right->left->key, 13);
    ASSERT_EQ(tree.root->right->right->key, 16);
    ASSERT_EQ(tree.root->left->left->left->key, 1);
    ASSERT_EQ(tree.root->left->left->right->key, 3);
    ASSERT_EQ(tree.root->left->right->left->key, 5);
    ASSERT_EQ(tree.root->right->left->left->key, 12);
    ASSERT_EQ(tree.root->right->left->right->key, 14);

    tree.insert(11, 77);

    ASSERT_EQ(tree.root->key, 7);
    ASSERT_EQ(tree.root->left->key, 4);
    ASSERT_EQ(tree.root->right->key, 13);
    ASSERT_EQ(tree.root->left->left->key, 2);
    ASSERT_EQ(tree.root->left->right->key, 6);
    ASSERT_EQ(tree.root->right->left->key, 12);
    ASSERT_EQ(tree.root->right->right->key, 15);
    ASSERT_EQ(tree.root->left->left->left->key, 1);
    ASSERT_EQ(tree.root->left->left->right->key, 3);
    ASSERT_EQ(tree.root->left->right->left->key, 5);
    ASSERT_EQ(tree.root->right->left->left->key, 11);
    ASSERT_EQ(tree.root->right->right->left->key, 14);
    ASSERT_EQ(tree.root->right->right->right->key, 16);

    tree.insert(10, 78);

    ASSERT_EQ(tree.root->key, 7);
    ASSERT_EQ(tree.root->left->key, 4);
    ASSERT_EQ(tree.root->right->key, 13);
    ASSERT_EQ(tree.root->left->left->key, 2);
    ASSERT_EQ(tree.root->left->right->key, 6);
    ASSERT_EQ(tree.root->right->left->key, 11);
    ASSERT_EQ(tree.root->right->right->key, 15);
    ASSERT_EQ(tree.root->left->left->left->key, 1);
    ASSERT_EQ(tree.root->left->left->right->key, 3);
    ASSERT_EQ(tree.root->left->right->left->key, 5);
    ASSERT_EQ(tree.root->right->left->left->key, 10);
    ASSERT_EQ(tree.root->right->left->right->key, 12);
    ASSERT_EQ(tree.root->right->right->left->key, 14);
    ASSERT_EQ(tree.root->right->right->right->key, 16);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
