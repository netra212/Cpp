#include <iostream>
using namespace std;

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




