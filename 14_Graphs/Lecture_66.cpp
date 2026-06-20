#include <iostream>
using namespace std;

bool Bellman_Ford(vector<vector<int>> &edges, vector<int> &dist){
    bool count = 1;
    for(int i = 0; i < edges.size(); i++){
        // dist[v] = min(dist[v], dist[u] + wt(u, v));
        if(dist[edges[i][1]] > dist[edges[i][0]] + dist[edges[i][2]]){
            dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
            count = 0;
        }
    }
    return count;
}

vector<int> bellmanfordAlgorithm(int V, vector<vector<int>> &edges, int S){
    vector<int> dist(V, 1e8);
    dist[S] = 0; // distance from source to source is zero.

    for(int i = 0; i < V-1; V++){ // Needs to run v-1 times cycle. 
        if(Bellman_Ford(edges, dist)){
            return dist;
        }
    }

    // Negative cycle. 
    if(!Bellman_Ford(edges, dist)){
        vector<int> temp;
        temp.push_back(-1);
        return temp;
    }

    return dist;
}


