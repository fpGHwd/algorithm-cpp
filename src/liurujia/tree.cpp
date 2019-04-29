//
// Created by suzumiya on 4/7/19.
//

#include "liurujia/tree.h"
#include <vector>
#include <queue>

using namespace std;

static Node *root; // sample root of a tree

void addnode(int v, char*s){
    return;
}

/**
 * BFS遍历
 * @param ans
 * @return
 */
bool bfs(vector<int>& ans){
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node *u = q.front();q.pop();
        if(!u->have_value)return false;
//        ans.push_back(u); // 已经使用了这个节点
        if(u->left)q.push(u->left);
        if(u->right)q.push(u->right);
    }
    return false;
}

/**
 * release a tree
 * @param u
 */
void remove_tree(Node* u){
    if(u == NULL)return; // if(!u->have_value)return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete(u);
}

void visit_recursion(vector<int>& ans, Node *u){
    if(u == NULL)return;
    // ans.push_back(u->v); // post
//    visit_recursion(u->left);
    ans.push_back(u->v); //
//    visit_recursion(u->right);
    // ans.push_back(u->v); //
}