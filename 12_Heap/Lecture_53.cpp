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

/**
Question: Find a Median in a stream. 
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5, 15, 1, 3

Output:
5
10
5
4
*/

class Solution{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> minHeap;
    double median;

    void insertHeap(int &x){
        // If heap is empty
        if(maxHeap.empty() && minHeap.empty()){
            median = x;
            maxHeap.push(x);
            return;
        }

        // If elements are present in heap. 

        // max heap --> Left side. 
        if(x<=median){
            maxHeap.push(x);
        }
        // min heap --> Right side. 
        else{
            minHeap.push(x);
        }
    }

    void balanceHeaps(){
        // Left side is greater. 
        if(maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else{
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double getMedian(){
        if(abs(maxHeap.size()-minHeap.size()) > 1){
            balanceHeaps();
        }

        // Max == Min
        if(maxHeap.size() == minHeap.size()){
            median = maxHeap.top() + minHeap.top();
            median /= 2;
        }
        // Max > Min 
        else if(maxHeap.size() > minHeap.size()){
            median = maxHeap.top();
        }
        // Max < Min
        else{
            median = minHeap.top();
        }

        return median;
    }
}

/**
Question: Smallest range in KList. 
Level: easy
Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at leat one element from each of the K lists. If more than one such range's are found, return the first such range found. 

Example 1:
N = 5, k = 3
KSortedArray[][] = {{1, 3, 5, 7, 9},
                    {0, 2, 4, 6, 8},
                    {2, 3, 5, 7, 11}
                    }
Output: 1 2
Explanation: K = 3
A: [1, 3, 5, 7, 9]
B: [0, 2, 4, 6, 8]
C: [2, 3, 5, 7, 11]

Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list. 
*/

int main(){

}



