#include <iostream>
using namespace std;

/**
 * BFS in Advanced. 
 */

/**
Find the number of islands. 
 */
bool check(int i, int j, int row, int col){
    return i > -1 && i < row && j > -1 && j < col;
}

void BFS(vector<vector<char>> & grid, int i, int j){
    int row[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    int n_row = grid.size();
    int m_col = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for(int k = 0; k < 8; k++){
            if(check(i+row[k], j+col[k], n_row, m_col) && grid[i+row[k]][j+col[k]] == '1'){
                grid[i+row[k]][j+col[k]] = '0';
                q.push({i+row[k], j+col[k]});
            }
        }
    }
}

int numIsLands(vector<vector<char>> & grid){
    int n_row = grid.size();
    int m_col = grid[0].size();

    int count = 0; // Count Number of Island. 
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < m_col; j++){
            if(grid[i][j] == '1'){
                grid[i][j] = '0';
                count++;
                BFS(grid, i, j);
            }
        }
    }
    return count;
}

/**
Steps by knight.
 */

bool check(int i, int j, int n){
    return i > 0 && i <= row && j > 0 && j <= col;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N){
    int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int row[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    // queue will store row, col, step of that particular pos of knight. 
    queue<pair<pair<int, int>, int>> q;
    q.push({{KnightPos[0], KnightPos[1]}, 0});

    // Jun position ma already gaisakeko cha, tyo position ma double patak najaoss vanerww. 
    vector<vector<bool>> visited(N+1,vector<bool> (N+1, 0));
    visited[KnightPos[0]][KnightPos[1]] = 1;

    int i, j, step=0;
    while(!q.empty()){
        i = q.front().first.first;
        j = q.front().first.second;

        if(i == TargetPos[0] && j == TargetPos[1]){
            return step;
        }
        
        step = q.front().second;

        for(int k = 0; k < 8; k++){
            if(check(i+row[k], j+col[k], N) && !visited[i+row[k]][j+col[k]]){
                visited[i+row[k]][j+col[k]] = 1;
                q.push({{i+row[k], j+col[k], step+1}});
            }
        }
    }

    return -1;
}

int main(){

}