#include <iostream>
#include <vector>
using namespace std;

bool sortBySecond(pair<int int> a, pair<int, int> b){
    return a.first < b.second || (a.second == b.second && a.first < b.first); 
}

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




