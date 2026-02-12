#include <iostream>
#include <queue>
using namespace std;

/**
Tree:
It is a type of Data Structure that represent a hierarchical relationships between data elements called nodes.

Count of edges : height
Degree: 2 because it has two child like 4, 5 so degree means no. of child. 

Binary tree is a defined as a tree data structure where each node has atmost 2 children.

If Binary tree contains n-node then total number of edge are: n-1
*/
class Node{
    public:
    int data;
    Node *left, *right;

    Node(int value){
        data = value;
        right = left = NULL;
    }
};


int main(){
    int x;
    cout << "Enter the root element: " << endl;
    cin >> x;

    int first, second;

    queue<Node*> q;
    Node *root = new Node(x);

    // Now, Build the Binary trees.
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left child of temp->data " << temp->data << " ";  
        cin >> first; // left node value. 
        // Left node. 
        if(first!=-1){
            temp->left = new Node(first);
            q.push(temp->left); // address pushed. 
        }
        // right node. 
        cout << "Enter the right child of temp->data " << temp->data << " ";  
        cin >> second; // left node value. 
         if(second!=-1){
            temp->right = new Node(second);
            q.push(temp->right); // address pushed. 
        }
    } 
}
