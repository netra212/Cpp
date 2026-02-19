#include <iostream>
#include <queue>
using namespace std;

// Q. Left View of Binary trees. 
vector<int> leftViewBinaryTree(Node *root){
    vector<int> ans;
    if(!root) return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data); // First element pushed into ans vector. 
        while(n--){
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

// solving above problems without using queue but only with recursion.
vector<int> leftViewBTRecursion(Node *root, int level, vector<int>&ans){
    if(!root) return ans;
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    leftViewBTRecursion(root->left, level+1, ans);
    leftViewBTRecursion(root->right, level+1, ans);
    return ans;
}

// Right view of Binary tree. 
vector<int> rightViewBT(Node *root){
    vector<int> ans;
    if(!root) return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data); // First element pushed into ans vector. 
        while(n--){
            Node *temp = q.front();
            q.pop();
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    return ans;
}

// Top view of Binary Tree.
void find(Node *root, int pos, int &left, int &right){
    if(!root) return;
    left = min(left, pos);
    right = max(right, pos);

    find(root->left, pos-1, left, right);
    find(root->right, pos+1, left, right);
}

vector<int> topViewBT(Node *root){
    int left = right = 0;
    find(root, 0, left, right);
    vector<int> ans(right - left +1);
    vector<bool> filled(right - left + 1, 0);
    queue<Node*> q;
    queue<int> index;
    q.push(root);
    index.push(-1*l);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if(!filled[pos]){
            filled[pos] = 1;
            ans[pos] = temp->data;
        }

        // Left. 
        if(temp->left){
            q.push(temp->left);
            index.push(pos-1);
        }
        // Right. 
        if(temp->right){
            q.push(temp->right);
            index.push(pos+1);
        }
    }
    return ans;
}

// solving above question with Recurison. 
void find(Node *root, int pos, int &left, int &right){
    if(!root) return;
    left = min(left, pos);
    right = max(right, pos);

    find(root->left, pos-1, left, right);
    find(root->right, pos+1, left, right);
}
void Tview(Node *root, int pos, int pos, vector<int> &ans, vector<int> &level, int left){
    if(!root) return NULL;
    if(level[pos] > left){
        ans[pos] = root->data;
        level[pos] = left;
    }
    Tview(root->left, pos-1, ans, level, left+1);
    Tview(root->right, pos+1, ans, level, left+1);
}
vector<int> topViewBinaryTree(Node *root){
    int l = 0, r = 0;
    find(root, 0, l, r);
    vector<int> ans(r-l+1);
    vector<int>level(r-l+1, INT_MAX);
    Tview(root, -1*l, ans, level, 0);
    return ans;
}

int main(){

}




