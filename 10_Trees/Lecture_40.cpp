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

Node *BinaryTree(){
    int x;
    cin >> x;

    if(x == -1){
        return NULL;
    }

    Node *root = new Node(x);
    cout << "Enter the left child of " << x << " \n";
    root->left = BinaryTree();
    cout << "Enter the right child of " << x << " \n";
    root->right = BinaryTree();

    return root;
}

void inOrder(Node *root){
    if(!root)return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root){
    if(!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << "[ "<< root->data << " ]";
}

void LevelwiseTreeTraversal(Node *root){
    if(!root) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right)
        }
    }
}

int getSize(Node *root){
    if(!root){
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

// Counting the total number of leaf nodes in the Binary trees.
int countLeafNodes(Node *root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return 1;
    }
    return (countLeafNodes(root->left) + countLeafNodes(root->right));
}

// size of Binary tree. 
int getSize(Node *root){
    if(!root){
        return 0;
    }
    return 1 + getSize(root->left) + getSize(root->right);
}

// sum of binary tree. 
int sumBT(Node *root){
    if(!root){
        return 0;
    }
    if(!root->left){
        return 0;
    }
    if(!root->right){
        return 0;
    }
    return root->data + sumBT(root->left->data) + sumBT(root->right->data);
}

int main(){
    Node *root = BinaryTree();
    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << "\nPreOrder Traversal: ";
    preOrder(root);
    cout << "\nPostOrder Traversal: ";
    postOrder(root);
    return 0;
}


