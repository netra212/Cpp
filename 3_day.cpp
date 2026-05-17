#include <iostream>
#include <vector>
using namespace std;

void print_graph(vector<vector<int>> adjacencyMatrix){
    for(int i = 1; i < 4; i++){
        cout << "Node: " << ", Neighbors: ";
        for(int j = 1; j <= 4; j++){
            if(adjacencyMatrix[i][j] == 1){
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

// Using Graphs. 
void print_graph1(unordered_map<int, vector<int>> graph){
    for(auto x: graph){
        cout << "Node: " << x.first << ", Neighbors: ";
        for(int nodes: x.second){
            cout << node << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> edgeList = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}
    }
    int n = 5; // represent number of edges or nodes. 
    vector<vector<int>> adjacencyMatrix(5, vector<int>(5, 0));
    for(int i = 0; i < edgeList.size(); i++){
        // un-directed graph. 
        int a = edgeList[i][0], b = edgeList[i][1];
        adjacencyMatrix[a][b] = 1;
        adjacencyMatrix[b][a] = 1;
    }
    print_graph(adjacencyMatrix);

    // Using a graph. 
    vector<vector<int>> edgeList1 = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}
    }
    unordered_map<int, vector<int>> graph;
    for(int i = 0; i < edgeList.size(); i++){
        // Un-directed graph. 
        int a = edgeList1[i][0], b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    print_graph1(graph);
}

