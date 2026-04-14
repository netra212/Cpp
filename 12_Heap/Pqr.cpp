#include <iostream>
#include <queue>
using namespace std;


int main(){
    // max heap
    priority_queue<int> p;
    // 1: Push
    p.push(4);
    p.push(9);
    p.push(2);
    p.push(7);
    p.push(8);
    cout << p.size();
    // 2: Pop
    p.pop(); // Delete the top element. 
    // 3: Find Value of max element or top element. 
    cout << p.top();
    // 4: Size of Heap
    // 5: Is Heap empty
    cout << p.empty();
    // min heap
    priority_queue<int, vector<int>, greater<int>>p1;
    p1.push(4);
    p1.push(8);
    p1.push(2);
    p1.push(7);
    cout << p1.size();
    return 0;
}


