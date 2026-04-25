#include <iostream>
using namespace std;
/**
# Graphs Traversal. 
1. BFS. 
**/

/**
Question: 1 - BFS of Graph. 

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0. 

Note: One can move from node u to node v only if there's an edge from u to v. Find the BFs traversal of the graph starting fro the 0th vertex, from left to right according to the input graph. Also, you should only taken nodes directly or indirectly connected from Node 0 in Consideration. 
*/

vector<iint> bfsOfGraph(int V, vector<int> adj[]){
    vector<int> ans;
    bool visited[V] = {0};
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()){
        node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i = 0; i < adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                q.push(adj[node][i]);
                visited[adj[node][i]] = 1;
            }
        }
    }
    return ans;
}

/**
You are given a connected undirected graph. Perform a Depth First Traversal of the Graph. 

Note: Use a recursive approach to find the DFS traversal of the graphs starting from the 0th vertext from left to right according to the graph. 
*/

void DFS(int node, vector<int> adj[], vector<int> &ans, vector<bool> &visited){

    if(!visited[node]){
        return 1;
    }

    visited[node] = 1;
    ans.push_back(node);

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
    int vertex, edges;
    cout << "Enter number of vertex: " << endl;
    cin >> vertex;
    cout << "Enter number of edges: " << endl;
    cin >> edges;

    int A[v][v]; // Creating matrix.

    int a, b;
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    // Creating an Adjancey matrix for Dense Graph. 
    vector<int> A[vertex];
    int a, b;
    for(int i = 0; i < edges; i++){
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    return 0;
}




