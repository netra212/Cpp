#include <iostream>
using namespace std;

/**
Question:-
Shortest Path from 1 to n. GeeksforGeeks.
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex j iff either j = i + 1 or j = 3 * i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.
*/

int minimumStep(int n){
    int count_edge = 0;
    while(n>=1){
        count_edge+= n%3;
        n/=3;
        count_edge++;
    };
    count_edge+=n;
    count_edge--;
    return count_edge;
}

int main(){

}


