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


/**
Question:
Find Center of star graph. 
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node. 

You are given 2D integer array edges where each edges[i] = [u_i, v_i] indicates that there is an edge between the nodes u_i and v_i. Return the center of the given star graph. 

Input Edges = [[1, 2], [2, 3], [4, 2]]
Output: 2

Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center. 
*/
int findCenter(vector<vector<int>> & edges){
    if(edges[0][0] == edges[1][0] || edge[0][0] == edges[1][1]){
        return edge[0][0];
    }
    return edges[1][0];
}


int main(){

}


