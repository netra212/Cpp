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

// Check either the Binary tree is Identical or not.
void isIdentical(Node *root1, Node *root2){
    if(!root1 && !root2){
        return 1;
    }
    if(!root1 &&root2|| root1 && !root2){
        return 0;
    }
    if(root1->data != root2->data){
        return 0;
    }
    return isIdentical(root1->left, root2->left) &&  isIdentical(root1->right, root2->right)
}

// 
int diameterOfTree(Node *root, int &ans){

}

/**
Calculate if the tree is balanced or not. 

Approach:
1. Calculate - height of left side of tree. 
2. Calculate - height of right side  of tree. 

then take the absolute difference between left and right height of tree. 
 */
int height(Node *root, int &ans){
    if(!root) return 0;
    int left = height(root->left, ans);
    int right = height(root->right, ans);
    if (abs(left-right)>1){
        ans = 0; // since, we will receive the unbalanced tree because diff betwee left and right subtree at every node will be greater than 1. so 
    }
    return 1 + max(left, right)
}

bool checkBalancedTree(Node *root){
    bool ans = 1;
    height(root, ans);
    return ans;
}

/**
Q. Left view of binary tree. 

Approach:
In this case, we need to implement a level order traversal.
Also, when we implements a level order traversal then we have to implement a queue for that. 
Think of it like a human-generation. 
First GrandFather Comes into a line for food. 
then he called his, daughter and son for food..
then daughter called her own one son. 
then son called his son and daughter for food.
similarly. 
*/
vector<int> leftView(Node *root) {
    // code here
    vector<int> ans;
    queue<Node *> q;
    if(!root) return ans;
    q.push(root);
    int size;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        size = q.size();
        while(size--){
            Node *temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return ans;
}
/**
Calculate the Bottom View of Binary Tree. 

Approach:

*/
void BottomViewBT(){

}


int main(){

}




