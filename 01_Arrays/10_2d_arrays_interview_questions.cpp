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
