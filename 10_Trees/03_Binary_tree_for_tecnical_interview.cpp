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

// Q. Count Leaves in Binary trees. 
int countLeafNodesOnBT(Node *root, int &count){
    /**
    Approach:
    ask every node -> Are you a Leaf node ?
    yes or no, 
    if yes, then count. 
    If no, then go to left side and right side. 
    */
    if(root == NULL){
        return 0; // becase this is not a leaf node.
    }
    if(!root->left & !root->right){
        return 1;
    }
    return (countLeafNodesOnBT(root->left, count)+countLeafNodesOnBT(root->right, count));
}

// Q. Count Non-Leaft Nodes. 
int countNonLeafNodes(Node *root){
    if(root == NULL){
        return 0;
    }
    if(!root->left && !root->right){
        return 0;
    }
    return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right))
}

// Q. Height of Binary trees.
int heightOfBinaryTrees(Node *root){
    if(root == NULL){
        return 0;
    }
    /**
    Sum of all the edges is the height of the binary trees. 
    */
    return 1 + max(heightOfBinaryTrees(root->left) ,heightOfBinaryTrees(root->right));
}

int main(){

}


