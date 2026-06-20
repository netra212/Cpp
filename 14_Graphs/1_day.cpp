#include <iostream>
using namespace std;

/**
# Graph: Data Structure

# Overview:
1. What are Graph ?
2. Types of Graph ?
3. How to Implement ?
4. Traversing a Graph. 
    - BFS + Question. 
    - DFS + Question.  
5. Cycle Detection. 
6. Topological sort. 
    - khan's algorithm. 
    - DFS - Based. 
7. Flood Fill. 
8. Connected Components. 
9. Shortest Path Algorithm. 
    - Single source (#3 algorithm).
    - Multi - source
10. DSU - Disjoint Union set. 
11. MST - Minimum Spanning Tree.  
    - Prim's. 
    - kruskal. 
12. Hamilton Path (TSP).
13. Graph Colouring. 
14. Strongly Connected Components. 
15. Network flow. 
    - Ford fulkerson. 
    - Edmond's karp. 
*/

vector<int> bfsOfGraph(int V, vector<int> adj[]){
    vector<int> ans;
    bool visited[V] = {0};
    queue <int> q;
    q.push(0);
    visited[0] = 0;
    int node;

    while(!q.empty()){
        node = q.front();
        q.pop();
        ans.push_back(node);
        // Going through the BFS...
        for(int i = 0; i < adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                q.push(adj[node][i]);
                visited[adj[node][i]] = 1;
            }
        }
    }
    return ans;
}

void DFS(int node, vector<int> adj[], vector<int> &ans, vector<bool> &visited){
    if(!visited[node]){
        return;
    }

    visited[node] = 1;
    ans.push_back(visited[node]);
    
    for(int i = 0; i < adj[node].size(); i++){
        DFS(adj[node][i], adj, ans, visited);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    vector<bool> visited(V, 0);
    vector<int> ans;

    DFS(0, adj, ans, visited);

    return ans;
}

int main(){

}