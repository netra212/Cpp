#include <iostream>
using namespace std;

/**
Question: Replace 0's with X's
*/
bool check(int i, int j, int n, int m){
    return i>-1 && j > -1 && i < n && j < m;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;

    // ans vector required. 
    vector<vector<char>> ans(n, vector<char> (m, 'X'));
    // visit vector required. 
    vector<vector<bool>> visit(n, vector<bool>(m, 0));

    // First row
    for(int j = 0; j < m; j++){
        if(mat[0] == 'O'){
            q.push({0, j});
            visit[0][j];
        }
        ans[0][j] = 'O';
    }
    // Last row
    for(int j = 0; j < m; j++){
        if(mat[n-1] == 'O'){
            q.push({n-1, j});
            visit[n-1][j];
        }
        ans[n-1][j] = 'O';
    }
    // First Col
    for(int i = 1; i < n-1; i++){
        if(mat[i][0] == 'O'){
            q.push({i, 0});
            ans[i][0] = 'O';
        }
        visit[i][0] = 1;
    }
    // Last Col
    for(int i = 1; i < n-1; i++){
        if(mat[i][m-1] == 'O'){
            q.push({i, m-1});
            ans[i][m-1] = 'O';
        }
        visit[i][m-1] = 1;
    }

    int u, v;
    while(!q.empty()){
        u = q.front().first;
        v = q.front().second;
        q.pop();
        
        for(int k = 0; k < 4; k++){
            if(check(u+row[k], v+col[k], n, m) && !visit[u+row[k]][v+col[k]]){
                visit[u+row[k]][v+col[k]] = 1;
                if(mat[u+row[k]][v+col[k]]) == 'O'{
                    ans[u+row[k]][v+col[k]] = 'O';
                    q.push({u+row[k], v+col[k]});
                }
            }
        }
    }
    return ans;
}

/**
// Question: Detech Cycle in a Directed Graph.
*/
bool DFS(vector<int> adj[], vector<bool> &visited, vector<bool> &path, int node){
    // 
    visited[node] = 1;
    path[node] = 1;
    for(int i = 0; i < adj[node].size(); i++){
        // Adjacent node is not visited. 
        if(visited[adj[node][i]] == 0){
            if(DFS(adj, visited, path, adj[node][i]))
            return 1;
        }
        // Adjacent node is visited. 
        else{
            // if path = 1, cycle present. 
            if(path(adj[node][i])){
                return 1;
            }
            // if path = 0, cycle not present. 
            // else{
            //     // Nothing happens here. 
            // }
        } 
    }
    path[node] = 0;
}

bool isCyclic(int V, vector<int> adj[]){
    // visited. 
    vector<bool> visited(V, 0);
    // path
    vector<bool> path(V, 0);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(DFS(adj, visited, path, i)){ // DFS -> detect either cycle is present or not. 
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

/**
# Topological Sort.
- A topological sort is an ordering of the vertices (nodes) of a directed acyclic graph (DAG) such that: For every directed edge u → v, node u comes before v in the ordering.
- Cyclic graphs does not have any topological sort. 

# 🔹 Key conditions:

The graph must be directed
It must have no cycles (no loop like A → B → C → A)

If there is a cycle, topological sorting is impossible.
# 🔹 Common algorithms
1. Kahn’s Algorithm (BFS-based):
    Repeatedly pick nodes with no incoming edges
2. DFS-based approach:
    Use depth-first search and stack ordering
Question: Topological sort.
*/

void DFS(vector<int> adj[], stack<int> &st, vector<bool> &visit, int node){
    visit[node] = 1;
    for(int i = 0; i < adj[node].size(); i++){
        if(!visit[adj[node][i]]){
            DFS(adj, st, visit, adj[node]);
        }
    }
    st.push(node);
    return;
}

vector<int> topoSort(int V, vector<int> adj[]){
    stack<int> st;
    vector<bool> visit(V, 0);
    for(int i = 0; i < V; i++){
        if(!visit[i]){
            DFS(adj, st, visit, i);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


/**
# Kahn's algorithms

1. Calculate In-Degrees: Scan the graph and count the in-degree (incoming edges) for every node.

2. Initialize a Queue: Find all nodes with an in-degree of 0 and push them into a queue.

3. Process the Queue: While the queue is not empty:
    a. Remove a node from the front of the queue and add it to your final sorted list.
    b. For every "neighbor" (node that depends on the current node), decrease their in-degree by 1 (since one of their prerequisites is now satisfied).
    c. If a neighbor's in-degree drops to 0, push that neighbor into the queue.
4. Cycle Detection: Once the queue is empty, compare the number of nodes you successfully processed to the total number of nodes in the graph. If the numbers don't match, your graph contains a cycle and a topological sort is impossible.
*/

vector<int> topoSortKahnAlgorithm(int V, vector<int> adj[]){
    vector<int> indeg(V, 0);
    for(int i = 0; i < V; i++){
        for(j = 0; j < adj[i].size(); j++){
            indeg[adj[i][j]]++;
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(!indeg[i]){
                q.push(i);
            }
        }

        vector<int> ans;
        int node;

        while(!q.empty()){
            node = q.front();
            q.pop();
            ans.push_back();
            for(int i = 0; i < adj[node].size(); i++){
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
    }
    return ans;
}



