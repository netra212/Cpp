#include <iostream>
using namespace std;

/**
Question:1 
Given a binary tree and an integer value K, the task is to find all nodes data in the given binary tree having exactly K leaves in sub-tree rooted with them. 

NOTE: nodes should be printed in the order in which they appear in postorder traversal. 
*/
int leaftCount(Node *root, vector<int> &ans, int k){
    if(!root){
        return 0;
    }
    if(!root->left & !root->right){
        return 1;
    }
    int left = leaftCount(root->left, ans, k);
    int right = leaftCount(root->right, ans, k);

    if(k == left + right){
        ans.push_back(root->data);
    }
    return left + right;
}

/**
Question: 2
The task is to complete the function findSpiral() which takes root nodes as input parameter and returns the elements in spiral form of level order traversal as a list. 
*/
vector<int> findSpiral(Node *root){
    vector<int> ans;
    queue<Node *>q;
    stack<Node *>s;
    if(!root){
        return ans;
    }
    q.push(root);
    Node *temp;
    bool dir = 0; // dir = 0, means move right to left. But dir = 1, means move left to right. 
    while(!q.empty()){
        // Right to Left. 
        if(dir == 0){
            int size = q.size();
            while(!q.empty()){
                temp = q.front();
                q.pop();

                if(temp->right){
                    s.push(temp->right);
                }

                if(temp->left){
                    s.push(temp->left);
                }
                ans.push_back(temp->data);
            }

            dir = 1;
        } else{
            // Left to Right. 
            int size = q.size();
            while(!q.empty()){
                temp = q.front();
                q.pop();

                if(temp->left){
                    s.push(temp->left);
                }

                if(temp->right){
                    s.push(temp->right);
                }
                ans.push_back(temp->data);
            }
            dir = 0;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return ans;
}

/**
Question: 3
Boundary traversal of a Binary tree. Question from GeeksForGeeks. 
*/

// Left subtree except leaf. 
void Left_sub(Node *root, vector<int> &ans){
    if(!root || !root->left && !root->right){
        return
    }
    ans.push_back(root->data);
    if(root->left){
        Left_sub(root->left, ans);
    }
    else{
        Left_sub(root->right, ans);
    }
    return;
}

// Reverse Right subtree except leaf.
void Leaf_sub(Node *root, vector<int> &ans){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    Leaf_sub(root->left, ans);
    Leaf_sub(root->right, ans);
}

// Reverse Right subtree except leaf. 
void Right_sub(Node *root, vector<int> &ans){
    if(!root || !root->left && !root->right){
        return;
    }
    if(root->right){
        Right_sub(root->right, ans);
    }
    else{
        Right_sub(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> Boundary(Node *root){
    vector<int> ans;
    ans.push_back(root->data);
    Left_sub(root->left, ans);
    if(root->left || root->right){
        Leaf_sub(root, ans);
    }
    Right_sub(root->right, ans);
    return ans;
}

