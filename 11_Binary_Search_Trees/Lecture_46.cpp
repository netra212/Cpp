#include <iostream>
using namespace std;

/**
# Check for BST.
*/
void Find(Node *root, int &prev_value, bool ans){
    if(!root) return;

    // Left side. 
    Find(root->left, prev_value, ans);

    // Right side. 
    Find(root->right, prev_value, ans);
}

bool isBST(Node *root){
    bool ans = 1; // assuming there is already a binary search tree. 
    int prev_value = INT_MIN;
    Find(root, prev_value, ans)
}

/*
# sum of kth smallest element in BST. 
*/
void findSumKthSmallestElement(Node *root, int &k, int &total){
    if(!root || k < 0) return;
    // Left side.
    findSumKthSmallestElement(root->left, k, total);
    k--;
    if(k>=0){
        total += root->data;
    }
    // Right side.
    findSumKthSmallestElement(root->right, k, total);
}
int sum(Node *root, int k){
    int total = 0;
    findSumKthSmallestElement(root, k, total);
    return total;
}


/**
# Given a BST, and a reference to a Node x in the BST. Find the InOrder Successor of the given node in the BST. 
*/
void FindSuccessor(Node *root, Node *&x, Node *&ans, bool &flag){
    if(!root || ans){
        return;
    }

    // Go to Left side. 
    FindSuccessor(root->left, x, ans, flag);
    if(flag){
        ans = root;
        return;
    }
    if(root=x){
        flag = 1;
    }
    // Go to Right side.
    FindSuccessor(root->right, x, ans, flag); 
}

Node *inOrderSuccessor(Node *root, Node *x){
    Node *ans = NULL;
    bool flag = 0;
    FindSuccessor(root, x, ans, flag);
    return ans;
}

/**
# Morris Traversal -> No Need of Recursion, stack, Queue.
*/
vector<int> inOrder(Node *root){
    vector<int> ans;
    // InOrder: Left Node Right
    while(root){
        // Left does not exist. 
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }
        // Left exist.
        else{
            Node *curr = root->left;
            // Find Right Most Node.
            while(curr->right && curr->right != root){
                curr = curr->right;
            }

            // If curr->right is null, then Form the Link. 
            if(!curr->right){
                curr->right = root;
                root = root->left;
            }else{
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        } 
    }
    return ans;
}

int main(){

}



