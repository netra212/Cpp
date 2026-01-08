#include <iostream>
using namespace std;

// Q. Rotate matrix by 90 clockwise.
void rotateMatrixBy90Clockwise(vector<vector<int>> &matrix)
{
    // This below code will takes an extra space.
    // int row = matrix.size();
    // int col = matrix[0].size();
    // int ans[row][col];
    int n = matrix.size();
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         ans[j][n - 1 - i] = matrix[i][j];
    //     }
    // }

    // More optimized way for solving this problem.
    // transpose of matrix.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Now, Reverse the each rows.
    int start = 0, end = n - 1;
    for (int i = 0; i < n; i++)
    {
        // reverseRows();
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
            start++, end--;
        }
    }
}

// Q. Rotating matrix by 180.
void rotateMatrixBy180Clockwise(vector<vector<int>> &matrix)
{
    // Approach: First Reverse all the columns...
    // then reverse all the rows.

    // Column-wise reverse.
    int n = matrix.size();
    for (int j = 0; j < n; j++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start][j], matrix[end][j]);
            start++, end--;
        }
    }

    // Row-wise reverse.
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start], matrix[i][end]);
        }
    }
}

// Q. Rotate Matrix 90' Anticlockwise. or it means rotate matrix 270' clockwise direction.
void rotateMatrix90DegreeAnticlockwise(vector<vector<int>> &matrix)
{
    // This is my home work.
}

// Q. Rotate Matrix by K time.
void rotateMatrixByKthTime(vector<vector<int>> &matrix)
{
    // Approach:
    // 1 time rotate means - 90 degree.
    // 2 time rotate means - 180 degree.
    // 3 time rotate means - 270 degree.
    // 4th time rotate means - 360 degree means matrix at original position.
    // 5th time rotate means - 90 degree.
    // 6th time rotate means - 180 degree.
    // 7th time rotate means - 270 degree.
}

int main()
{

    return 0;
}
