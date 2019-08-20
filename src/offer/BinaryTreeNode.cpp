//
// Created by suzumiya on 8/20/19.
//

#include <cstdio>
#include "BinaryTreeNode.h"

void BinaryTree::preorder_traverser_recursive(binary_tree root) {
    if(root!= nullptr){
        printf("%d\t", root->elem);
        preorder_traverser_recursive(root->left);
        preorder_traverser_recursive(root->right);
    }
}

void BinaryTree::inorder_traverse_recursive(binary_tree root) {
    if(root!= nullptr){
        inorder_traverse_recursive(root->left);
        printf("%d\t", root->elem);
        inorder_traverse_recursive(root->right);
    }
}

void BinaryTree::postorder_traverse_recursive(binary_tree root) {
    if(root!=nullptr){
        postorder_traverse_recursive(root->left);
        postorder_traverse_recursive(root->right);
        printf("%d\t",root->elem);
    }
}