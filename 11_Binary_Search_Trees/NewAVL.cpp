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

void updateHeight(Node *root){
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    root->height = 1 + max(leftHeight, rightHeight);

}
Node *rotateRight(Node *root){
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    return temp;
}

Node *rotateLeft(Node *root){
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    return temp;
}

Node *Balance(Node *root){
    if(!root){
        return NULL;
    }

    // Update the height. 
    updateHeight(root);

    // Calculate the Balance factor.
    int balance = getHeight(root->left) - getHeight(root->right);

    // Balance > 1 means Left is Unbalance.
    if(balance > 1){
        // Left Left Unbalance. 
        if(getHeight(root->left->left) >= getHeight(root->left->right)){
            root = rotateRight(root);
        }
        // Left Right Unbalance. 
        else{
            root->left = rotateLeft(root->left);
            root = rotateRight(root->right);
        }
    }
    // Balanced < -1 means Right is Unbalance. 
    else if(balance<-1){
        // Right Right Unbalance. 
        if(getHeight(root->right->right) >= getHeight(root->right->left)){
            root = rotateLeft(root);
        }
        // Left Right Unbalance. 
        else{
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
    return root;
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

void inorder(Node *root){
    if(!root){
        return;
    }
    inorder(root->left);
    count << root->data;
    inorder(root->right);
}

void preOrder(Node *root){
    if(!root){
        return;
    }
    count << root->data;
    inorder(root->left);
    inorder(root->right);
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

    inorder(root);
    cout << endl;
    preOrder(root);
    return 0;
}