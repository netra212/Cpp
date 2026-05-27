#include <iostream>
using namespace std;

/**
 * Shortest Path in Undirected Graph Having Unit Distance. 
 * Approach:
 * steps: 
 * 1. push source node into queue. 
 * 2. run loop till queue is empty. 
 * 3. Pop the source node. 
 * 4. Now, Find all the neighbour of popped node with BFS. 
 * 5. Two Condition.
 *      a. If neighbour is already visited. 
 *              Don't do anything. 
 *      b. But if neighbour is not visited. 
 *              then add distance by 1. 
 *              and Push that neigbour into queue. 
 * 
 */

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src){
   /**
    * N -> represent number of nodes. 
    * M -> represent number of edges. 
    */
  // Creating an Adjacent List. 
   vector<int> adj[N];
   for(int i = 0; i < M; i++){
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
   }

   // Creating distance vector with size of number of Node.
   vector<int> distance(N);
   // return vector of distance. 
   for(int i = 0; i < N; i++){
        distance[i] = -1;
   }

   distance[src] = 0;

   // Queue store : Node + distance from source node. 
   queue<pair<int, int>> q;

   q.push({src, 0});

   int i, step;
   while(!q.empty()){
        i = q.front().first;
        step = q.front().second;
        q.pop();

        for(int k = 0; k < adj[i].size(); k++){
            // if adjacent node is not visited yet. 
            if(distance[adj[i][k]] == -1){
                q.push({adj[i][k],step + 1});
                distance[adj[i][k]] = step + 1;
            }
        }
   }

   return distance;
}


int main(){

}



