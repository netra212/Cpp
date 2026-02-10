#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Display queue element. 
void display(queue<int>q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Q. Print all numbers in every window of size k. 
void PrintAllNumberEveryWindowSizeK(int k){
    /**
    arr = [3, 6, 2, 7, 8, 11]
    Ans:-
        FirstWindowAns = [3, 6, 2]
        SecondWindowAns = [6, 2, 7]
        ThirdWindowAns = [2, 7, 8]
        4thWindowAns = [7, 8, 11]
        and Like that. 
     */
    queue<int> q;
    for(int i = 0; i < k-1; i++){
        q.push(arr[i]); // pushing element up to k-1. 
    }
    // Now, Push the k-1 element and start displaying the element from the front. 
    for(int i = k - 1; i < n; i++){
        q.push(arr[i]);
        display(q);
        q.pop(); // removing the element of queue from the front. 
    }
}

// Q. Find the First negative number in every window of size.
void FirstNegativeNumberEveryWindowSize(int k){
    /**
    arr = [2, -3, -4, -2, 7, 8, 9, -10]
     */
}
int main(){
    // 
}