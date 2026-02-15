#include <iostream>
#include <queue>
using namespace std;

// Q. Left View of Binary trees. 
vector<int> leftViewBinaryTree(Node *root){
    vector<int> ans;
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
}

int main(){

}




