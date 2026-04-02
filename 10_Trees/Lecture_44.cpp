#include <iostream>
using namespace std;

/**
Question 1: 

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one special nodes to another special node. 

Basically, Question means to calculate the sum from one leaf node to another leaf node. 

*/

int maxSum(Node *root, int &sum){
    // If root is null. 
    if(!root){
        return 0;
    }

    // If left node and right node of root does not exist means leaf node. 
    if(!root->left & !root->right){
        return root->data;
    }

    // calculate the sum of left part. 
    int left = maxSum(root->left, sum);

    // Calculate the sum of right part. 
    int right = maxSum(root->right, sum);

    // If Left and right of root node exit. 
    if(root->left && root->right){
        sum = max(sum, root->data + left + right);
        return root->data + max(left, right);
    }else if(root->left){
        return root->data + left;
    }else{
        return root->data + right;
    }
}

int maxPathSum(Node *root, int sum){
    int sum = INT_MIN;
    int value = maxSum(root, sum);
    if(root->left && root->right)
    {
        return sum;
    }
    return max(sum, value);
}

/**
Burning Tree
Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
*/

int Burn(Node *root, int target, int &timer){
    if(!root){
        return 0;
    }

    // Since this will be burning nodes. 
    if(root->data == target){
        return -1;
    }
    int left = Burn(root->left, target, timer);
    int right = Burn(root->right, target, timer);

    // If value of left is negative then left is burning. 
    if(left<0){
        timer = max(timer, abs(left) + right);
        return left - 1;
    }
    // If value of right is negative then right is burning. 
    else if(right <0){
        timer = max(timer, left + abs(right));
        return right - 1;
    }
    // If left and right both comes in positives then left and right are not burning yet. 
    return max(left, right)+1;
}
void Find(Node *root, int target, Node * &temp){
    if(!root){
        return;
    }

    if(root->data == target){
        temp = root;
    }

    Find(root->left, target, temp);
    Find(root->right, target, temp);
}

int Height(Node * &temp){
    if(!root){
        return 0;
    }
    return 1 + max(Height(root->left), Height(root->right));
}

int minTime(Node *root, int target){
    int timer = 0;
    Burn(root, target, timer);
    Node *temp;
    Find(root, target, temp);
    int num = Height(temp) - 1;
    return max(timer, num);
}

int main(){
    //
}


