#include <iostream>
using namespace std;

/**
# Binary Search tree. 
*/
class Node{
    public:
        int data;
        Node *left, *right;
    
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}

Node *BST(Node *root, int value){
    // if root is NULL. 
    if(!root){
        root = new Node(value);
        return root;
    }
    // If root is not NULL
    // Go to Left Side. 
    if(root->data > value){
        root->left = BST(root->left, value);
        return root;
    }
    // Go to Right Side. 
    else{
        root->right = BST(root->right, value);
        return root;
    }
}

void inOrder(Node *root){
    if(!root){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

/**
# Search a Node in Binary Search Tree. 
*/
bool search(Node *root, int x){
    if(!root){
        return 0;
    }

    if(root->data == x){
        return 1;
    }

    if(root->data > x){
        return search(root->left, x);
    }else{
        return search(root->right, x);
    }
}

/**
# Given a Binary search tree. The task is to find the minimum valued element in this given BST. 
*/
int minValue(Node *root){
    if(!root) return -1; 
    return !root->left ? root->data : minValue(root->left);
}

/**
# Kth Largest element in BST. 
Your task is to complete the function which will return the Kth largest element without doing any modification in Binary search tree.
*/
void Find(Node *root, int &k, int &ans){
    if(!root || k<0){
        return;
    }
    Find(root->right, k, ans);
    k--;
    if(k==0){
        ans = root->data;
        return;
    }
    Find(root->left, k, ans);
}
int kthLargestElementInBST(Node *root, int K){
    int ans;
    Find(root, K, ans);
    return ans;
}

// Kth smallest. 
// Insert a Node in a Binary search tree. 
// Sum of Kth smallest element in BST. 

int main(){
    int arr[10] = {10, 13, 4, 8, 11, 19, 2, 7, 18, 23};
    Node *root = NULL;
    for(int i = 0; i < 10; i++){
        root = BST(root, arr[i]);
    }
    inOrder(root);
    return 0;
}

