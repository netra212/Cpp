#include <iostream>
using namespace std;

/**
Question 1: 

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special nodes to another special node. 

Basically, Question means to calculate the sum from one leaf node to another leaf node. 

*/

int maxSum(Node *root, int &sum){
    // If root is null. 
    if(!root){
        return 0;
    }

    // If left node and right node of root does not exist means leaf node. 
    if(!root->left & !root->right){
        return root->data;
    }

    // calculate the sum of left part. 
    int left = maxSum(root->left, sum);

    // Calculate the sum of right part. 
    int right = maxSum(root->right, sum);

    // If Left and right of root node exit. 
    if(root->left && root->right){
        sum = max(sum, root->data + left + right);
        return root->data + max(left, right);
    }else if(root->left){
        return root->data + left;
    }else{
        return root->data + right;
    }
}

int maxPathSum(Node *root, int sum){
    int sum = INT_MIN;
    int value = maxSum(root, sum);
    if(root->left && root->right)
    {
        return sum;
    }
    return max(sum, value);
}

/**
Burning Tree
Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
*/
int main(){
    // 
}


