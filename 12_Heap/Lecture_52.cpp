#include <iostream>
#include <vector>
using namespace std;

bool sortBySecond(pair<int int> a, pair<int, int> b){
    return a.first < b.second || (a.second == b.second && a.first < b.first); 
}

/**
# Merge sorted arrays. 
Question: You are given K sorted integers arrays in a form of 2D integers matrix A of size K X N. You need to merge them into a single arrays and return it.
Example Input:
Input: 
A = [
    [1, 2, 3],
    [2, 4, 6],
    [0, 9, 10]
]
Example Output:
[0, 1, 2, 2, 3, 4, 6, 9, 10]
*/
void mergeSortedArrays(vector<vector<int>> &A){
    vector<int> ans; 
    int row = A.size();
    int column = A[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair <int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap; // value, row, column_number.
    // So need to make an pair like this pair<int, pair<int, int> p;

    // Insert first column into minHeap;
    for(int i = 0; i < row; i++){
        minHeap.push(make_pair(A[i][0], make_pair(i, 0)));
    }

    pair<int, pair<int, int>> p;
    while(!minHeap.empty()){
        // get minimum element from the top of the heap. 
        p = minHeap.top();

        // Insert a value into a `ans` vector. 
        ans.push_back(p.first);
        row = p.second.first;
        column = p.second.second;
        minHeap.pop();
        // Insert the next element of that row, first check whether that row is exhausted or not. 
        if(col < A[0].size()-1){
            minHeap.push(make_pair(A[row][col+1]), make_pair(row, col+1));
        }
    }
    return ans;
}

/**
# Huffman Encoding. 
Suppose..,
String S = A B B C D A B D ..... 
A = 20, A -> 0100001 -> 2^6 + 1-> 64 + 1 => 65
B = 4   B -> 8 Bits
C = 15  C -> 8 Bits
D = 9   D -> 8 Bits
E = 2   E -> 8 Bits
And So on....
*/




int main(){
    // Creating a Pair. 

    // First Method. 
    pair <int, int> p1;
    p1.first = 10;
    p1.second = 20;
    cout << "Values: " << "first: " << p1.value << " second: " << p1.second << endl;
    
    pair <int, pair<int, int>> p2;
    pair <pair<int, char>, pair<int, int>> p3;
    p3.first.first = 10;
    p3.first.second = 20;
    p3.second.first = 4;
    p3.second.second = 6;
    cout << p3.first.first << p3.first.second << p3.second.first << p3.second.second;

    // Another way of creating Pair in C++.
    pair <int, int> p;
    p = make_pair(10, 20);
    cout << p.first << " " << p.second;

    vector <pair<int, int>> v;
    v.push_back(make_pair(10, 20));
    v.push_back(make_pair(4, 7));
    v.push_back(make_pair(4, 9));
    v.push_back(make_pair(6, 9));
    v.push_back(make_pair(1, 21));

    // Ascending order: On the basis of first. 
    sort(v.begin(), v.end());

    // Descending Order: On the basis of first. 
    sort(v.rbegin(), v.rend());

    for(int i = 0; i < 5; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    // Ascending Order on the basis of second. 
    sort(v.begin(), v.end(), sortBySecond);
    // Descending Order on the basis of second. 
    return 0;
}




