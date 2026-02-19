#include <iostream>
using namespace std;

// PreOrder traversal: Node Left Right. 
// InOrder traversal: Left Node Right.
// PostOrder traversal: Left Right Node. 
vector<int> preOrderIterative(Node *root){
    stack<Node *>s;
    s.push(root);
    vector<int> ans;
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
    return ans;
}

vector<int> postOrderIterative(Node *root){
    stack<Node *>s;
    s.push(root);
    vector<int> ans;
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->left){
            s.push(temp->left);
        }
        if(temp->right){
            s.push(temp->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

}