#include <iostream>
using namespace std;

/**
# Smallest range in KList. 
Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found. 

Example 1:
Input:
N = 5, K = 3
KSortedArray[][] = {{1, 3, 5, 7, 9},
                    {0, 2, 4, 6, 8},
                    {2, 3, 5, 7, 11}}
Output: 1 2
Explanation:  K = 3
A:[1, 3, 5, 7, 9]
B:[0, 2, 4, 6, 8]
C:[2, 3, 5, 7, 11]
*/

pair<int, int> findSmallestRange(int arr[][N], int n, int k){
    // pair<value, pair<row, col>> p;
    pair<int, pair<int, int>> p;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    int min = INT_MAX;
    int max = INT_MIN;
    int row, col;

    // Create minHeap with k elements. 
    for(int i = 0; i < k; i++){
        row = i;
        col = 0;
        minHeap.push(make_pair(arr[row][col]),make_pair(row, col));
        min = min(mini, arr[row][col]);
        max = max(max, arr[row][col]);
    }

    int start = min;
    int end = max; 

    pair<int, pair<int, int>> temp;

    while(!minHeap.empty()){
        temp = minHeap.top();
        minHeap.pop();
        row = temp.second.first;
        col = temp.second.second;
        min = temp.first;
    }

    if(end - start > max-min){
        end = max;
        start = min;
    }
    if(col = N - 1){
        break;
    }else{
        max = max(max, arr[row][col+1]);
        minHeap.push(make_pair(arr[row][col+1], make_pair(row, col+1)));
    }
    return {start, end};
}

int main(){

}



