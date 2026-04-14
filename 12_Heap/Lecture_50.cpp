#include <iostream>
#include <vector>
using namespace std;

/**
# Question: Implement a Maxheap/MinHeap using arrays and recursion. 
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

void Heapify(vector<int> &maxHeap, int index){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    int size = maxHeap.size();
    // First Check for Left side. 
    if(left < size && maxHeap[left] > maxHeap[largest]){
        largest = left;
    }
    // Then Check for right side. 
    if(right < size && maxHeap[right] > maxHeap[largest]){
        largest = right;
    }

    if(largest != index){
        swap(maxHeap[largest], maxHeap[index]);
        Heapify(maxHeap, largest);
    }
    return;
}

void DeleteHeap(vector<int> &maxHeap){
    // Replace first element by last elment. 
    maxHeap[0] = maxHeap[maxHeap.size()-1];
    // Delete the last element. 
    maxHeap.pop_back();
    // Heapify: Correct Position.
    Heapify(maxHeap, 0);
}

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

    DeleteHeap(maxHeap);
    DeleteHeap(maxHeap);

    for(int i = n/2-1; i>=0; i--){
        Heapify(maxHeap, i);
    }
    
    cout << "Heap Created with this element: "
    for(int i = 0; i < maxHeap.size(); i++){
        cout << maxHeap[i] << " ";
    }
    return 0;
}



