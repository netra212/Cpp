#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int data){
        data = value;
        left = right = NULL;
    }
};

// Q. Level Order Traversal.
vector<int> levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    Node *temp;
    while(!q.empty()){
        temp = q.front();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){

}


