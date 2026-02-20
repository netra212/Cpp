#include <iostream>
using namespace std;

// Construct a Tree from inOrder and Preorder. 
/**
in  -> [4, 2, 8, 5, 9, 1, 6, 3, 7, 10]
        0  1  2  3  4  5  6  7  8   9
pre -> [1, 2, 4, 5, 8, 9, 3, 6, 7, 10]

If pre and post order are given then we cannot create a unique trees.
pre & in -> only one unique tree can be created.
pos & in -> only one unique tree can be created. 

Approach:
1. Check the first element from the pre-order. 
2. Check the post of first element(from preorder) into the inorder. 
3. And, divide into left and right. 
 */

// in  -> [4(inStart), 2, 8, 5, 9, 1(pos), 6, 3, 7, 10(inEnd)]
//         0  1  2  3  4  5  6  7  8   9
// pre -> [1(index), 2, 4, 5, 8, 9, 3, 6, 7, 10]
 
// Finding the Position inorder. 
int find(int *inorder, int target, int start, int end){
    for(int i = start; i<= end; i++){
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
} 

Node *Tree(int inorder[], int preorder[], int inStart, in inEnd){
    if(inStart > inEnd){
        return NULL;
    }
    Node *root = new Node(preorder[index]);
    int pos = findPos(inorder, preorder[index], inStart, inEnd);
    // Build left part
    root->left = Tree(inOrder, preorder, inStart, pos-1, index + 1);
    // Build right part
    root->right = Tree(inorder, preorder, pos+1, inEnd, index+(pos-inStart)+1);
    return root;
}

Node *buildTree(int inorder[], int preorder[], int n){
    return Tree(inorder, preorder,0, n-1, 0)
}

// Construct a Tree from in order and Post order. 
/**
in  -> [4 2 6 5 7 1 10 8 9 3]
pos -> [4 6 7 5 2 10 9 8 3 1]
*/
Node *Tree(int inorder[], int postorder[], int inStart, in inEnd, int index){
    if(inStart > inEnd){
        return NULL;
    }
    Node *root = new Node(postorder[index]);
    int pos = findPos(inorder, postorder[index], inStart, inEnd);
    // Build right part
    root->right = Tree(inorder, postorder, pos+1, inEnd, index-1);
    // Build left part
    root->left = Tree(inOrder, postorder, inStart, pos-1, index - (inEnd-pos)-1);
    return root;
}

int main(){

}


