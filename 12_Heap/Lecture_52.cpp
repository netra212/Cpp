#include <iostream>
#include <vector>
using namespace std;

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
    return 0;
}




