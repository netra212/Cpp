#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

//  Creating Binary trees via given arrays. 
Node *BinaryTrees(){
    int x;
    cin >> x;
    if(x == -1){
        // no need to create node here. 
        return NULL;
    }
    Node *temp = new Node(x);
    cout << "Enter the left child of " << x << " ";
    temp->left = BinaryTrees(); // Left node create.
    cout << "Enter the right child of " << x << " ";
    temp->right = BinaryTrees(); // Right node create. 
    return temp;
}

// Q. Pre-order traversal. 
void preOrderTraversal(Node *root){
    // First Visit Node
    // Go to Left
    // Go to Right
    if(root == NULL){
        return;
    }
    cout << root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Q. In order traversal.
void inOrderTraversal(Node *root){
    // Go to Left
    // Visit Node
    // Go to Right
    if(root == NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data;
    inOrderTraversal(root->right);
}

// Q. post order traversal.
void postOrderTraversal(Node *root){
    // Go to Left
    // Go to Right
    // Visit Node
    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data;
}

int main(){
    cout << "Enter the root Node: ";
    Node *root;
    root = BinaryTrees();

    // Pre-order print:
    cout << "Pre order: " << endl;
    preOrderTraversal(root);

    // In-order traversal.
    cout << "In order traversal: " << endl;
    inOrderTraversal(root);

    // Post-order print:
    cout << "Post Order: " << endl;
    postOrderTraversal(root);
}