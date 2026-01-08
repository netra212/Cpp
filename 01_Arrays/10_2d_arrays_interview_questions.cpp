/**
 * Column wise or Column Major.
 *
 * Vector in 2D Arrays.
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Printing the values of 2D vectors in wave forms.

/**
 * 3, 6, 4, 2
 * 7, 8, 11, 5
 * 9, 3, 2, 1
 * 17, 8, 5, 9
 * Output value: 3, 7, 9, 17, 8, 3, 8, 6, 4, 11, 2, 5, 9, 1, 5, 2
 * Approach:
 * col -> even -> (up -> down)
 * col -> odd -> (down -> up)
 *
 for(int j = 0; j < col; j++){
    if(j%2 == 0){
        // Print from up to down.
        for(int i = 0; i < rows; i++){
            cout << arr[i][j];
        }
    }
    else{
        // Print from down to up.
        for(int i = row-1; i >= 0; i--){
            cout << arr[i][j];
        }
    }
 }
 * Time Complexity:O(rowxcol)
 *
 *
 */

// Printing the 2D Vectors in wave forms.
void waveForms(int arr[][4], int row, int col)
{
    //
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < row; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int i = row - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

// Printing the array in the spiral forms.
// 3, 6, 49, 2
// 7, 8, 11, 5
// 9, 3, 21, 1
// 1, 8, 51, 9
// Approach or patterns: print top rows, then print right column, then print bottom rows, then print left column.
/*
 top = 0    (row)
 right = 4  (column)
 bottom = 4 (row)
 left = 0   (column)

 while(top <= bottom && left <= right){
    for(int j = left; j <= right; j++){
        cout << matrix[top][j];
        top++;
    }

    for(int i = top; i <= bottom; i++){
        cout << matrix[i][right];
        right--;
    }

    for(int j = right; j>= left; j--){
        cout << matrix[bottom][j];
        bottom--;
    }

    for(int i = bottom; i>= top; i--){
        cout << matrix[i][left]
        left++;
    }
 }
*/

vector<int> spiralForms(vector<vector<int>> &matrix, int row, int col)
{
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int top = 0, bottom = row - 1, left = 0, right = col - 1;

    while (left <= right && top <= bottom)
    {
        // print top.
        for (int j = left; j <= right; j++)
        {
            ans.push_back(matrix[top][j]);
            top++;
        }

        // print right.
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
            right--;
        }

        // print bottom.
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
                bottom--;
            }
        }

        // print left.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
                left++;
            }
        }
    }

    return ans;
}

// Q. Transpose Matrix.
/**
 * 1, 2, 3, 4
 * 5, 6, 7, 8
 * 9, 1, 2, 3
 * 3, 4, 1, 2
 *
 */
void transposeMatrix(vector<vector<int>> &matrix, int row, int col)
{
    vector<vector<int>> transposedMatrix(4, 4);
    int n = matrix.size(); // size of rows.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
}

// Program executed from below.
int main()
{
    int rows, column;

    cout << "Enter rows and column: " << " ";
    cin >> rows >> column;

    // Create 2D vector.
    vector<vector<int>> matrix(rows, vector<int>(column, 1));

    // Taking matrix values from the user.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Printing the 2D vector.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }
    cout << "Rows = " << matrix.size();
    cout << "Cols = " << matrix.size();
}
