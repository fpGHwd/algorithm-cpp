//
// Created by suzumiya on 8/20/19.
//

#ifndef BEAUTY_IN_CODE_BINARYTREENODEDOUBLE_H
#define BEAUTY_IN_CODE_BINARYTREENODEDOUBLE_H

typedef struct binary_tree_node{
    int elem;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
}binary_tree_node, *binary_tree;

struct BinaryTreeNodeDouble{
    double                      m_dbValue;
    BinaryTreeNodeDouble*       m_pLeft;
    BinaryTreeNodeDouble*       m_pRight;
};

class BinaryTree {
public:
    void preorder_traverser_recursive(binary_tree root);
    void inorder_traverse_recursive(binary_tree root);
    void postorder_traverse_recursive(binary_tree root);

};

// 非成员声明
//void BinaryTree::preorder_traverse_recursive1(binary_tree *root);


#endif //BEAUTY_IN_CODE_BINARYTREENODEDOUBLE_H
