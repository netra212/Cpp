#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        data = value;
        left = right = NULL;
    }
};

// Q. Level Order Traversal.
vector<int> levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    Node *temp;
    while(!q.empty()){
        temp = q.front();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

// Q. size of binary tree. 
void sizeBinaryTree(Node *root, int &count){
    /**
    If we need node, then increase count++
    then go to left side and right side. 
    */
    if(root == NULL){
        return;
    }
    count++;
    sizeBinaryTree(root->left, count);
    sizeBinaryTree(root->right, count);
}

// Another method to calculate the size of binary trees.
int totalNodes(Node *root){
    if(root == NULL){
        return 0;
    }
    return (1 + totalNodes(root->left) + totalNodes(root->right));
}

// Q. Sum of Binary trees
int sumBinaryTrees(Node *root){
    if(root == NULL){
        return 0;
    }
    return (root->data + sumBinaryTrees(root->left) + sumBinaryTrees(root->right));
}

int main(){

}


