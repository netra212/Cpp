#include <iostream>
using namespace std;
/**
Calculate the nodes at odd level. 
*/
void PreOrder(Node *root,vector<Node *> &ans, int level){
    if(!root) return;
    if(level%2==1){
        ans.push_back(root);
    }
    PreOrder(root->left, ans, level+1);
    PreOrder(root->right, ans, level+1);
}

vector<Node*> nodesAtOddLevels(Node *root){
    vector<Node *> ans;
    int level = 1;
    PreOrder(root, ans, level);
    return ans;
}

/**
Approach:
1. Left subtree -> sum. 
2. Right subtree -> sum. 
3. if(leftSum + rightSum != root->value)
*/

int sumTree(Node *root, bool &ans){
    if(!root) return 0;

    // Identifying the leaf note. 
    if(!root->left && !root->right){
        return root->data;
    }

    // left sum.
    int left = sumTree(root->left, ans);

    // right sum.
    int right = sumTree(root->right, ans);
    if(left + right != root->data){
        ans = 0;
    }
    return root->data + left + right;
}

bool isSum(Node *root){
    bool ans = 1;
    sumTree(root, ans);
    return ans;
}

/**
Root to leaf paths sum. 
*/
findSum(Node *root, long long &sum, long long num){
    
    // NOT COMPLETE THIS QUESTIONS. 
    findSum(root->left, sum, num*10);
    findSum(root->right, sum, num*10);
}

long long treePathsSum(Node *root){
    long long sum = 0;
    long long num = 0;
    findSum(root, sum, num);
    return sum;
}

/**
Maximum difference between Node and its ancestor. 
*/

int main(){
   
}

