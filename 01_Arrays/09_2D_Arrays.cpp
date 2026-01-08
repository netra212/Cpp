/***
 * 2D Arrays
 *
 */

#include <iostream>
using namespace std;

// print column wise.
void printColumnWise(int arr[][4], int row, int col)
{
    // column wise.
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

int rowMajor(int arr[], int num)
{
    // index = row_index * col + col_index
    // row_index = index / col
    // col_index = index % col

    // Creating 2-D arrays.
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Element to be search.
    int x = 17;

    // // print all the value in array row wise.
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 4; col++)
    //     {
    //         if (arr[row][col] == x)
    //         {
    //             return 0;
    //         }
    //     }
    // }

    cout << "No" << " " << endl;

    // print all the value in array column wise, function call.
    // printColumnWise(arr, 3, 4);
}

// Q. searching an element in arrays.
void searchElementInArrays(int arr[], int num)
{
    //
}

// Add 2 Matrix.
void addTwoMatrix()
{
    //
    int arr1[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[4][3] = {0, 1, 3, 4, 6, 7, 10, 11, 41, 18, 11, 12};

    int ans[4][3];
    // Add two matrix with same size.
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            ans[row][col] = arr1[row][col] + arr2[row][col];
        }
    }

    // Printing...
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << ans[row][col] << " ";
        }
    }
}

// Q. Print row index with Max sum.
void rowIndexWithMaxSum()
{
    //
}

//
int main()
{
    return 0;
}
