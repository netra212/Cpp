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

/**
Question: 2: Calculate the Height of the heap. 
Level: Basic
*/
int heapHeight(int n, int arr[]) {
    // code here
    if(n == 0){
        return 0;
    }
    
    // If heap contains single element means height 1. 
    if(n==1){
        return 1;
    }
    
    return (int)floor(log2(n));
}

/**
Question: 
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 
Level: Medium

# Approach:-
1. Create a minHeap. 
2. then pop every 2 elements. 
*/
int minCost(vector<int>& arr) {
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>>p;
    for(int i = 0; i < arr.size(); i++){
        p.push(arr[i]);
    }
    
    int first, second;
    while(p.size() != 1){
        first = p.top();
        p.pop();
        second = p.top();
        p.pop();
        first += second;
        cost += first;
        p.push(first);
    }
    return cost;
}

/**
# Magician and Chocolates

Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

NOTE: floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7


*/
int nchoc(int A, int* B, int n2) {

}


/**
Questions: 
Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order. 
Level: Medium
*/
int main(){

}

