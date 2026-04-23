#include <iostream>
using namespace std;

/**
Question: 1 First Repeating Element.
Given an integer Array of size N, find the first repeating element in it. 

We need to find the element that occurs more than once and whose index of first occurence is smallest. 

If there is no repeating element, return -1.
*/

int firstRepeatingElement(vector<int> &A){
    int ans = -1;
    unordered_map<int, bool> m;

    for(int i = A.size()-1; i>=0; i--){
        // Check Either element is repeated or not. 

        // Repeated. 
        if(m.count(A[i])){
            ans = A[i];
        }
        // Not repeated. 
        else{
            m[A[i]] = 1;
        }
    }
    return ans;
}

/**
Question: Subarrays with equal 1s and 0s. 
Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.
n = 7
A[] = {1, 0, 0, 1, 0, 1, 1}
total number of subarrays. 
*/

long long int countSubArrayWithEqualZeroAndOne(int arr[], int n){
    int sum = 0;
    long long final_count = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            sum++;
        }else{
            sum--;
        }

        final_count += m[sum];
        m[sum]++;
    }
    return final_count;
}

/**
Question: Subarray with B odd numbers. 

Given an array of integers A and an integer B. 
Find the total number of subarrays having exactly B odd numbers. 

Example Input:
A = {4, 3, 2, 3, 4}
B = 2
*/

int solve(vector<int> &A, int B){
    unordered_map<int, int>m;
    // total = count of odd, sum = number of subarray. 
    int total = 0, sum = 0;
    m[0] = 1;
    for(int i = 0; i< A.size(); i++){
        // Count Number of odd. 
        if(A[i]%2){
            total++;
        }
        // Increase the Map. 
        m[total]++;
        // B = 0.
        if(B==0){
            sum+=m[total-B]-1;
        }
        // Include that in sum.
        else if(m.count(total-B)){
            sum+=m[total-B];
        }
    }
    return sum;
}

/**
# Equal 0, 1 & 2.
Given a string str of length N which consist of only 0, 1, or 2s, count the number of substring which have equal number of 0s, 1s and 2s. 

Input: 
str = "0102010"
Output: 2
*/
long long getSubstringWithEqual012(string str){
    // 
}


int main(){

}



