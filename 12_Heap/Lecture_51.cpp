#include <iostream>
using namespace std;

/*
# Given an array of size N. The task is to sort the array elements by completing function heapify() and buildHeap() which are used to implement Heap Sort.
Level : Medium
*/

void heapify(int maxHeap[], int size, int index){

    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

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
        heapify(maxHeap, size, largest);
    }
}

void buildHeap(int arr[], int n){

}

void heapSort(int arr[], int n){
    // First Create max heap. 
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    // Heap sort. 
    for(int i = n-1; i >=; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main(){

}