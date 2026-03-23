#include <iostream>
using namespace std;

/**
Question:1 
Given a binary tree and an integer value K, the task is to find all nodes data in the given binary tree having exactly K leaves in sub-tree rooted with them. 

NOTE: nodes should be printed in the order in which they appear in postorder traversal. 
*/
int leaftCount(Node *root, vector<int> &ans, int k){
    if(!root){
        return 0;
    }
    if(!root->left & !root->right){
        return 1;
    }
    int left = leaftCount(root->left, ans, k);
    int right = leaftCount(root->right, ans, k);

    if(k == left + right){
        ans.push_back(root->data);
    }
    return left + right;
}
