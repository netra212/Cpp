#include <iostream>
using namespace std;

/**
Question: Huffman Related Question. 
[5, 9, 12, 13, 16, 45]
*/
class Node{
    public:
    int freq;
    Node *left, *right;

    Node(int count){
        freq = count;
        left = right = NULL;
    }
};

class compare{
    public:
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }

    void pre_order(Node *root, string s, vector<string> &Huff){
        if(!root){
            return;
        }

        if(!root->left && !root->right){
            Huff.push_back(s);
            return;
        }
        // Now, left
        pre_order(root, s+'0', Huff);
        // Now, right
        pre_order(root, s+'1', Huff);
    }

    // vector<int> f contains the frequency of each character.
    vector<string> huffmanCodes(string S, vector<int> f,,int N){
        // create min heap.
        priority_queue<Node *, vector<Node*>, compare> minheap;

        // Push every character in heap. 
        for(int i = 0; i < N; i++){
            Node *ans = new Node(f[i]);
            minheap.push(ans);
        }

        Node *root;
        // first two minimum element or node. 
        Node *min1, *min2;
        while(minheap.size() > 1){
            // Extract two minimum elements or node. 
            min1 = minheap.top();
            minheap.pop();
            min2 = minheap.top();
            minheap.pop();

            // Now combining the frequency of two first minimum elements. 
            root = new Node(min1->freq+ min2->freq);
            root->left = min1;
            root->right = min2;
        }

        root = minheap.top();
        vector<string> huff;

        // Now, printing the tree in pre_order_traversal. 
        pre_order(root, "", huff);
        return huff;
    }
};

int main(){

}



