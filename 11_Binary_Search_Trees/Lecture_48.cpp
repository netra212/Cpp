#include <iostream>
using namespace std;

/**
// Question: 1: Delete a Node from a BST.

Given a Binary Search Tree and a Node value x. Delete the Node with the given value x from the BST. If no Node with value x exist, then do not make any changes. 
*/

Node *minValue(Node *root){
    Node *current = root;
    while(current && current->left){
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int x){
    // Check if either root is NULL or not. 
    if(!root) return NULL;

    // I found the Node or x value is equal to the root value. 
    if(root->data == x){
        // 0 Child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 Left Child
        else if(root->left && !root->right){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // 1 Right Child
        else if(!root->left && root->right){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 Child
        else{
            Node *temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    // Or x value is less than root's value. 
    else if(x < root->data){
        root->left = deleteNode(root->left, x);
    }
    // Or x value is greater than root's value. 
    else{
        root->right = deleteNode(root->right, x);
    }
}

/**
# Balanced Binary search tree. 
-1 <= (left_height - right_height) <= 1
*/

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node *CreateBBST(vector<int> &v, int start, int end){

    if(start > end){
        return NULL;
    }

    int mid = start + (end - start)/2;
    Node *root = new Node(v[mid]);

    root->left = CreateBBST(v, start, mid-1);
    root->right = CreateBBST(v, mid + 1, end);
    return root;
}

void inOrder(Node *root){
    if(!root){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root){
    if(!root){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    // First: sort the arrays. 
    sort(v.begin(), v.end());

    int start = 0, end = n-1;
    Node *root = CreateBBST(v, start, end);
    inOrder(root);
    return 0;
}

