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

// Q. calculate either two trees are identical. 
bool checkTwoTreesAreIdentical(Node *root1, Node *root2){
    /**
    two trees will be identical if every node of tree has same data->value. 
     */
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    if((!root1 && root2) ||(root1 && !root2)){
        return 0;
    }
    if(root1->data != root2->data){
        return 0;
    }
    return (checkTwoTreesAreIdentical(root1->left, root2->left) && checkTwoTreesAreIdentical(root2->right, root2->right));
}

// Q. Mirror trees. 
bool mirrorTree(Node *root){
    /**
            1
          /   \
        3       2
              /    \
            5       4
        mirror tree
            1
          /   \
        2       3
      /   \
    4      5
     */
    if(!root){
        return;
    }

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Q. Check for Balance tree.
void checkBalanceTree(){
    /**
    -1 <= height(left) - height(right) <= 1
     */
}

int main(){

}



