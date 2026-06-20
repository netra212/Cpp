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
    // 1: Bridge not present. 
    // 0: Bridge present. 
    return !DFS(c, d, adj, visited);
}

/**
 * Q. Strongly Connected Component (Kosaraju's algorithm)
 * Use case of scc:
 * 1. Highway. 
 * 2. 
 */
void DFS(int node,vector<vector<int>> &adj, stack<int> &s, vector<bool> &visited){
    visited[node] = 1;
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]]){
            DFS(adj[node][i], adj, s, visited);
        }
    }

    s.push(node);
}

void SCC(int node, vector<bool> &visited, vector<vector<int>> &trans){
    visited[node] = 1;
    for(int i = 0; i < trans[node].size(); i++){
        if(!visited[trans[node][i]]){
            SCC(trans[node][i], visited, trans);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj){
    // Modified Topological sort. 
    stack<int> s;
    vector<bool> visited(V, 0);
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            DFS(i, adj, s, visited);
        }
    }
    // Transpose the graph, reverse the edges. 
    vector<vector<int>> trans(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            trans[adj[i][j]].push_back(i); // reversing the edges. 
        }
    }
    int count_scc = 0;
    for(int i = 0; i < V; i++){
        visited[i] = 0;
    }
    // stack element pop, DFS operation. 
    while(!s.empty()){
        // if top element of stack is not visited, increase count_scc by 1.  
        if(!visited[s.top()]){
            count_scc++;
            SCC(s.top(), visited, trans);
        }
        s.pop();
    }
    return count_scc;
}

/**
 * Bellmond ford Algorithm. 
 */
