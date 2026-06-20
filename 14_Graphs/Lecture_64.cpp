#include <iostream>
using namespace std;

/**
 * Prim's Algorithm
 * How the Prims Algorithms Works.
 */
int minSpanningTree(int V, vector<vector<int>> adj[]){
    // 3D: vector<vector<int>> arr[]
    // 2D: vector<int> arr[]
    // 1D: int arr[]

    // Weight
    vector<int> weight(V, INT_MAX);

    // parent
    vector<int> parent(V, -1);

    // visited. 
    vector<bool> visited(V, 0);
    int count_vertex =0;
    int cost = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0}); // path, Node. 

    int Node, path, adjNode, adjPath;

    while(!q.empty()){
        path = q.top().first;
        Node = q.top().second;
        q.pop();

        // If node is already visited, skip the step. 
        if(visited[Node] == 1){
            continue;
        }
        count_vertex++;
        cost += path;

        // Else, Node is not visited yet. 
        visited[Node] = 1;

        if(count_vertex == V){
            break;
        }

        // Marks that node as visited, i.e., 1 and Look at Adjacent Node. 

        for(int i = 0; i < adj[Node].size(); i++){
            adjNode = adj[Node][i][0];
            adjPath = adj[Node][i][1];

            if(!visited[adjNode] && adjPath < weight[adjNode]){
                q.push({adjPath, adjNode});
                parent[adjNode] = Node;
                weight[adjNode] = adjPath;
            }
        }
    }

    for(int i = 1; i < V; i++){
        cost+= weight[i];
    }

    return cost;
}

/**
 * Kruskal Algorithm. 
 */
int findParent(int u, vector<int> &parent){
    if (u == parent[u]){
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

bool unionSet(int u, int v, vector<int> &rank, vector<int> &parent){
    int p_u = findParent(u, parent);
    int p_v = findParent(v, parent);
    if(p_u == p_v){
        return 1; // already connected. 
    }

    if(rank[p_u] == rank[p_v]){
        rank[p_u]++;
        parent[p_v] = p_u;
    }
    else if(rank[p_u] < rank[p_v]){
        parent[p_u] = p_v;
    }
    else{
        parent[p_v] = p_u;
    }
    return 0; // means diconnected theeya. 
}
int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for(int i = 0; i < V; i++){
        parent[i] = i; // making every node parent itself. 
    }

    // min heap, insert every edge. 
    priority_queue<pair<int, int>, int>, vector<pair<pair<int, int>>>, greater<pair<int, int>, int>> q;

    int u, v, w;
    for(int i = 0; i < V; i++){
        for(int j = 0; i < adj[i].size(); j++){
            u = i;
            v = adj[i][j][0];
            w = adj[i][j][1];

            q.push({w, u}, v);
        }
    }
    int count_edges = 0;
    int cost = 0;

    while(!q.empty()){
        if(count_edges == V-1){
            break;
        }

        w = q.top().first.first;
        u = q.top().first.second;
        v = q.top().second;
        q.pop();

        if(unionSet(u, v, rank, parent)){
            continue;
        }
        count_edges++;
        cost += w;
    }
    return cost;
}



/**
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
-----------------------------------
Prim's Algorithm
Time Complexity: O(E log V)
-----------------------------------
*/

int minSpanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> weight(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, 0});

    int cost = 0;

    while (!pq.empty())
    {
        int path = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;

        cost += path;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int adjNode = adj[node][i][0];
            int adjWeight = adj[node][i][1];

            if (!visited[adjNode] &&
                adjWeight < weight[adjNode])
            {
                weight[adjNode] = adjWeight;
                parent[adjNode] = node;

                pq.push({adjWeight, adjNode});
            }
        }
    }

    return cost;
}

/*
-----------------------------------
Disjoint Set Functions
-----------------------------------
*/

int findParent(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;

    return parent[u] =
           findParent(parent[u], parent);
}

bool unionSet(
    int u,
    int v,
    vector<int> &rank,
    vector<int> &parent)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if (pu == pv)
        return true;

    if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else if (rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else
    {
        parent[pv] = pu;
        rank[pu]++;
    }

    return false;
}

/*
-----------------------------------
Kruskal's Algorithm
Time Complexity: O(E log E)
-----------------------------------
*/

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    // Insert all edges
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j][0];
            int w = adj[i][j][1];

            pq.push({w, {u, v}});
        }
    }

    int cost = 0;
    int edgesUsed = 0;

    while (!pq.empty() &&
           edgesUsed < V - 1)
    {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;

        pq.pop();

        if (unionSet(u, v, rank, parent))
            continue;

        cost += w;
        edgesUsed++;
    }

    return cost;
}