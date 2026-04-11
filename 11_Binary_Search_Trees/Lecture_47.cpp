#include <iostream>
using namespace std;

/**
# Question: 1
PreOrder to PostOrder.
Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact PostOrder from it's given preorder traversal. 

In Pre-Order traversal, the root node is visited before the left child and right child nodes.

Given arrays: [40, 30, 35, 80, 100]

PreOrder: Node Left Right
PostOrder: Left Right Node
*/
Node* Find(int pre[], int min, int max, int &index, int size){
    if(!index>=size || pre[index] > end) return NULL; 

    Node *root = new Node;
    root->data = pre[index];
    index++;

    if(index == size){
        return root;
    }
    root->left = Find(pre, min, root->data, index, size);
    root->right = Find(pre, root->data, max, index, size);
    return root;
}

Node* preOrder_to_postOrder(int pre[], int size){
    int min = INT_MIN, max = INT_MNAX, index = 0;
    return Find(pre, min, max, index, size);
}

/**
Question 2: Find the closet element in the BST. 

Given a BST and an integer. Find the least absolute difference between any node value f the BST and the given integer. 
*/
int minDiff(Node *root, int k){
    if(!root) return INT_MAX;

    if(k == root->data){
        return 0;
    } else if(k > root->data){
        // Goes to right side.
        return min(k - root->data, minDiff(root->right, k));
    } else{
        // Goes to Left side. 
        return min(root->data - k, minDiff(root->left, k));
    }
}


/**
# Ceil in BST. 
You are given a root binary search tree and an integer x . Your task is to find the Ceil of x in the tree.
Note: Ceil(x) is a number that is either equal to x or is immediately greater than x.
If Ceil could not be found, return -1.
 */
int findCeil(Node* root, int x) {
    if (!root) return -1;
        
    if (root->data == x) {
        return root->data;
    }
    else if (root->data > x) {
        // Current node is greater than x
        // Check if left subtree has a better (smaller) ceil
        int leftResult = findCeil(root->left, x);
        
        if (leftResult != -1) {
            return leftResult;  // Found a smaller valid number
        } else {
            return root->data;  // No better option, use current node
        }
    }
    else {  // root->data < x
        // Current node is too small, check right subtree
        return findCeil(root->right, x);
    }
}

/**
# PreOrder Traversal and BST. 
Level: Medium
Given an arrays arr[] of size N consisting of distinct integers, write a program that return 1 if given array can represent preorder traversal of a possible BST, else return 0.

// Example: 1
N = 3
arr = {2, 3}
Output: 1
Explanation: Given arr[] can represent preorder traversal of following BST. 
2
 \
  4
 /
3

// Key insights to solve above question. 
In preorder traversal of a BST:
    1. You visit: Root → Left Subtree → Right Subtree
    2. All nodes in left subtree are smaller than root
    3. All nodes in right subtree are larger than root
*/


/**
# Bheem wants Ladoos.

Choota Bheem wants to eat the maximum number of ladoos in Dholakpur on independence day. The house in Dholakpur are arranged in form a binary tree and have ladoos the same as their house number. Choota Bheem is standing as his home initially. 

Find the maximum ladoos he can eat if he can go to the houses within a maximum distance k from his house. The number of ladoos at his home should also be included in the sum. 

NOTE: Every house has distinct ladoos in it. 
Example 1:

         1
        / \
       2   9
      /   /  \
     4   5    7

home = 9, k = 1
Explanation
Initially Bheem at 9, so sum = 9
In 2nd move he went to 5, sum = 9 + 5 = 14
In 3rd move he went to 7, sum = 14 + 7 = 21
In 4th move he went to 1, sum = 21 + 1 = 22
so within k distance bheem can get 22 ladoos. 

HINT:
Level Order traversal Implements. 
*/

/**
# Minimum Absolute Difference In BST. 

# Given a binary search tree of size N > 1, the tasks is to find the minimum absolute difference between any two nodes. 
*/

/**
# Fixing Two swapped nodes of a BST. 

Two of the nodes of a Binary Search Trees (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree. 

NOTE: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. 
*/


/**
# Merge Two BSTs. 

// GeeksforGeeks. 
*/


/**
# Shortest range in BSTs. 
 */



