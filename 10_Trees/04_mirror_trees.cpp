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

int height(Node *root, bool &valid){
    if(!root){
        return 0;
    }
    // Check height of left part. 
    int L = height(root->left, valid);
    // Check height of right part. 
    int R = height(root->right, valid);
    if(abs(L-R)>1){
        valid = 0; // means no balance tree. 
    }
    return 1 + max(L, R);
}

// Q. Check for Balance tree.
bool isBalanceTree(Node *root){
    /**
    -1 <= height(left) - height(right) <= 1
    */
    bool valid = 1; // assuming tree is balance for initial stage. 
    height(root, valid);
    return valid;
}

// Q. Level order traversal in spiral forms. 
void levelOrderTraversalInSpiralForms(Node *root){
    /**
                        1
                      /    \
                     2       3
                    /  \    /  \
                   4    5   6   7
                  /      \     /  \
                 8        9    12   13
     */
    stack<Node *> s1; // Right to Left. 
    stack<Node *> s2; // Left to Right.  

    s1.push(root);
    vector<int>ans;

    while(!s1.empty() || !s2.empty()){
        // Right to Left. 
        if(!s1.empty()){
            while(!s1.empty()){
                Node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);

                // Right.
                if(temp->right){
                    s2.push(temp->right);
                }
                // Left. 
                if(temp->left){
                    s2.push(temp->left);
                }
            }
        }else{
            // Left to Right. 
             while(!s2.empty()){
                Node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);

                // Right.
                if(temp->right){
                    s1.push(temp->right);
                }
                // Left. 
                if(temp->left){
                    s1.push(temp->left);
                }
            }
        }
    }
    return ans;
}

bool parent(Node *root, int a, int b){
    if(!root){
        return 0;
    }
    if(root->left && root->right){
        if(root->left->data == a && root->right->data == b){
            return 1; // means parents are same. 
        }
        if(root->left->data == b && root->right->data == a){
            return 1; // means parents are also same. 
        }
    }
    return parent(root->left, a, b) || parent(root->right, a, b);
}

// Q. Check if 2 Nodes are cousin. 
bool checkIf2NodesAreCousin(Node *root, int a, int b){
    /**
    1. Two level must be in same level. 
    2. Parents of two nodes must be different. 
                        1
                      /    \
                     2       3
                    /  \    /  \
                   4    5   6   7
                  /      \     /  \
                 8        9    12   13
    cousinNodes are:
    2, 3
    4, 5, 6, 7 and so on...

    // Approachs:
    1. Needs to find a Level. implementLevelOrderTraversal.
    2. 
    */
    queue<Node *> q;
    q.push(root);
    int level1 = -1, level2 = -1;
    int level = 0;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node *temp = q.front();
            q.pop();
            if(temp->data == a){
                level1 = level;
            }
            if(temp->data == b){
                level2 = level;
            }

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        level++;
        if(level1 != level2){ // not in same level.
            return 0;
        }
        if(level1 != -1){ // Now in same level.
            break;
        }
    }
    return !parent(root, a, b);
}

int main(){

}



