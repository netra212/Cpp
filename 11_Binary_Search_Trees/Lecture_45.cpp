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

int main(){
    int arr[10] = {10, 13, 4, 8, 11, 19, 2, 7, 18, 23};
    Node *root = NULL;
    for(int i = 0; i < 10; i++){
        root = BST(root, arr[i]);
    }
    inOrder(root);
    return 0;
}

