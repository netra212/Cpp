#include <iostream>
using namespace std;

/**
 * Graph Advanced Euler.
 */

/**
 * Flyod Warshall.
 */

void shortest_distance(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}

/**
 * Euler Circuit in an Undirected Graph. 
 */

void DFS(int node, vector<int> adj[], vector<bool> &visited){
    visited[node] = 1;
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]]){
            DFS(adj[node][i], adj, visited);
        }
    }
}

bool isEularCircuitExit(int V, vector<int> adj[]){
    vector<int> degree(V, 0);
    // Finding the degree of every nodes. 
    for(int i = 0; i < V; i++){
        degree[i] = adj[i].size();
    }

    // Check if degree even or odd. 
    for(int i = 0; i < V; i++){
        if(degree[i] % 2){ // If degree odd then cannot do traversal. 
            return 0;
        }
    }

    int node = -1;
    for(int i = 0; i < V; i++){
        if(degree[i]){
            node = i;
            break;
        }
    }

    // If edges does not exist, means returned. 
    if(node == -1){
        return 1;
    }

    // Traverse the whole circuit. 
    vector<bool> visited(V, 0);
    DFS(node, adj, visited);

    // if node not visited but degree exist mean not a part of eular circuit part. 
    for(int i = 0; i < V; i++){
        if(!visited[i] && degree[i]){
            return 0;
        }
    }

    return 1;
}

/**
 * Circle of string: Hard Level. 
 * ab, bc, da, cd
 * two words will combine if first and last character of two words are same. 
 * Example:
 * adeb     bhac    dopa    chad
 * adeb --connect--bhac chad--connect--dopa
 */







