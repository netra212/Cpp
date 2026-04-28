#include <iostream>
using namespace std;

/**
DFS: traverse with focus in-depth. 
In DFS, We don't get one answer. We will get multiple answer. 
**/

void dfs(int node, unordered_map<int, vector<int>> graph, int n, vector<int> &visited){
    cout << node <<  " ";
    visited[node] = 1;

    for(int nbr: graph[node]){
        if(!visited[nbr]){
            dfs(nbr, graph, n, visited);
        }
    }
}

int main(){
    vector<vector<int>> edgeList = {
        {0, 1}, {1, 4}, {1, 2}, {2, 3}
    };

    int n = 5;

    unordered_map<int, vector<int>> graph;
    for(int i = 0; i < edgeList.size(); i++){
        // un-directed graph. 
        int a = edgeList[i][0], b = edgeList([i][1]);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << "DFS Order: ";
    vector<int> visited(n);
    dfs(0, graph, n visited);
}


