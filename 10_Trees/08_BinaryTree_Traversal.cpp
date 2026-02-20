#include <iostream>
using namespace std;

/**
# Vertical Traversal of Binary tree. 
*/
void find(Node *root, int pos, int &l, int &r){
    if(!root){
        return;
    }
    l = min(l, pos);
    r = max(l, pos);

    find(root->left, pos-1, l, r);
    find(root->right, pos+1, l, r);
}

vector<int> verticalOrder(Node *root){
    int l = 0, r = 0;
    find(root, 0, l, r);

    // Positive
    vector<vector<int>> Positive(r+1);

    // Negative
    vector<vector<int>> Negative(abs(l)+1);

    queue<Node *>q;
    q.push(root);
    queue<int> index;
    index.push(0);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if(pos>=0){
            Positive[pos].push_back(temp->data);
        }else{
            Negative[abs(pos)].push_back(temp->data)
        }

        // Left value. 
        if(temp->left){
            q.push(temp->left);
            index.push(pos-1);
        }
        // Right value. 
        if(temp->right){
            q.push(temp->right);
            index.push(pos+1);
        }
    }

    // Negative.
    // Positive.
    vector<int>ans;
    for(int i = Negative.size()-1; i>0; i--){
        for(int j = 0; j<Negative[i].size(); j++){
            ans.push_back(Negative[i][j]);
        }
    }
    for(int i = 0; i<Positive.size(); i--){
        for(int j = 0; j<Positive[i].size(); j++){
            ans.push_back(Positive[i][j]);
        }
    }
    return ans;
}

/**
Diagonal Traversal of Binary tree. 
*/
void find1(Node * root, int pos, int &l){
    if(!root){
        return;
    }
    l = max(pos, l);
    find(root->left, pos+1, l);
    find(root->right, pos, l);
}
void findDiagonal(Node *root, int pos, vector<vector4<int>> &ans){
    if(!root){
        return;
    }
    ans[pos].push_back(root->data);
    findDiagonal(root->left, pos+1, ans);
    findDiagonal(root->right, pos, ans);
}
vector<int> diagonalTraversalBT(Node *root){
    int l = 0; // left most diagonal.
    find1(root, 0, l);
    vector<vector<int>> ans(l+1);
    findDiagonal(root, 0, ans);
    vector<int> temp;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans.size(); j++){
            temp.push_back(ans[i][j]);
        }
    }
    return temp;
}

/**
Boundary Traversal.
 */

boundaryTraversal(Node *root){

}

int main(){

}


