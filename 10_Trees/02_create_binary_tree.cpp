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

int main(){
    cout << "Enter the root Node: ";
    Node *root;
    root = BinaryTrees();
}