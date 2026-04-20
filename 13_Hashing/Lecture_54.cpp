#include <iostream>
#include <map>
using namespace std;

/**
# Hashing
{13, 12, 34, 56, 78, 19, 24, 52}

Problems on Hashing:
- Collision

# Better solution: 
    -> better hash function. 
    -> Chaining

Chaining Like this.. 
First calculate the module of each element in arrays. 
{13%10, 12%10, 34%10, 56%10, 78%10, 19%10, 24%10, 52%10}
- Output: {3, 2, 4, 6, 8, 9, 4, 2} <-- value after module... which will insert into the arrays of 10 size suppose for now. 

Open Address Solution:

*/
class DSA{
    string name;
    int marks;
};


/**
# Map. 
map<_, _> m1;
In map, key -> must be unique. 
But there is a concept of multi-map.
Map means Balanced Binary search tree. 

# Time complexity: 
    search: O(logn)
    insert: O(logn)
    delete: O(logn)
*/

/**
Question: First element to occur k times. 
arr = [1, 7, 4, 3, 4, 8, 7]
k = 2
Find a element which appears Ktimes. 
since 4 appears 2 times in above arrays
so that 4 is final answer.
*/

int firstElementKTime(int a[], int n, int k){
    // number, count. 
    unordered_map<int, int>m;
    for(int i = 0; i < n; i++){
        // If 1 does not exist, create and insert 1 over there. 
        // 1 exist karta hai, increase count by 1. 
        // m[a[i]]++;
        if(m.count(a[i]) == 0){
            m[a[i]] = 1;
        }else{
            m[a[i]++];
        }

        // 
        if(m[a[i]] == k){
            return a[i];
        }
    }
    return -1;
}

/**
Question: Largest subarray with 0 sum. 
N = 8
A[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with sum 0 will be -2, 2 -8 1 7
*/
int maxLen(vector(vector<int> &A, int n){

}

int main(){
    map<int, int> m;

    // Insert the data. 
    m[2] = 8;
    m[9] = 15;
    m[1] = 7;
    m[4] = 6;

    // Check where key is exist or not. 
    cout << m.count(9) << " "; // 1 means exist, 0 means does not exist. 

    for(auto i = m.begin(); i < m.end(); i++){
        cout << i->first << " " << i->second << endl;
    }

    cout << m[2] << " ";
}


