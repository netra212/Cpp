#include <iostream>
using namespace std;

/**
// Lecture 45
# Question 1:
Construct a binary tree from InOrder and PreOrder. 
*/

int Find(int inOrder[], int num, int start, int end){
    for(int i = start; i <= end; i++){
        if(inOrder[i] == num){
            return i;
        }
    }
}
Node * constructBT(int inOrder[], int preOrder[], int start, int end, int index){
    // Base condition. 
    if(start>end){
        return NULL;
    }
    Node *root = new Node(preOrder[index]);
    int i = Find(inOrder, preOrder[index], start, end);
    root->left = constructBT(inOrder, preOrder, start, i-1, index + 1);
    root->right = constructBT(inOrder, preOrder, i+1, end, index + (i-start)+1);
    return root;
}
Node *buildTree(int in[], int pre[], int n){
    Node *root;
    root = constructBT(in, pre, 0, n - 1, 0);
    return root;
}

int main(){

}