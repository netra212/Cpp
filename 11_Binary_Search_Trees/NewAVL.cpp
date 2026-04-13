#include <iostream>
using namespace std;

class Node{
    public:
    int data, height;
    Node *left, *right;

    Node(int value){
        data = value;
        height = 1; // height of single node is 1. 
        left = height = NULL;
    }
};

int getHeight(Node *root){
    if(!root){
        return 0;
    }
    return root->height;
}

Node *rotateRight(Node *root){
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node *rotateLeft(Node *root){
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

Node *Balance(Node *root){
    
}

Node *insertBST(Node *root, int value){
    if(!root){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insertBST(root->left, value);
    }else{
        root->right = insertBST(root->right, value);
    }
    return Balance(root);
}

int main(){
    Node *root = NULL;
    int value;
    while(1){
        cin >> value;
        if(value != -1){
            root = insertBST(root, value);
        }else{
            break;
        }
    };
}