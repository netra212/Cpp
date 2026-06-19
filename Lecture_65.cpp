#include <iostream>
using namespace std;

/**
 * Q. Bridge Edge in a Graph [GFG]
 */

bool DFS(int node, int target, vector<int> adj[], vector<int> &visited){
    if(node == target){
        return 1;
    }else{
        visited[node] = 1;
        for(int i = 0; i < adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                if(DFS(visited[adj[node][i]], target, adj, visited)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int isBridge(int V, vector<int> adj[], int c, int d){
    for(int i = 0; i < adj[c].size(); i++){
        if(adj[c][i] == d){
            adj[c][i] = c;
            break;
        }
    }
    for(int i = 0; i < adj[d].size(); i++){
        if(adj[d][i] == c){
            adj[d][i] = d;
            break;
        }
    }

    vector<int> visited(V, 0);
    DFS(c, d, adj, visited);
}

