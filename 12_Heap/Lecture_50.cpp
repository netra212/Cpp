#include <iostream>
#include <vector>
using namespace std;

/**
Question: Implement a Maxheap/MinHeap using arrays and recursion. 
*/
void insertHeap(vector<int> &maxHeap){
    int index = maxHeap.size()-1;
    int parent;
    while(index>0){
        parent = (index - 1)/2;
        // Parent is small.
        if(maxHeap[parent] < maxHeap[index]){
            swap(maxHeap[parent], maxHeap[index]);
            index = parent;
        }
        // Parent is big.
        else{
            break;
        }
    }
}

/**
# Question-2: Height of the Heap:
*/

int main(){
    vector<int> maxHeap;
    int n, element;
    cout << "Enter size of heap: ";
    cin >> n;
    cout << "Enter the element for heap: "
    for(int i = 0; i < n; i++){
        cin >> element;
        maxHeap.push_back(element);
        insertHeap(maxHeap);
    }
    cout << "Heap Created with this element: "
    for(int i = 0; i < maxHeap.size(); i++){
        cout << maxHeap[i] << " ";
    }
    return 0;
}



