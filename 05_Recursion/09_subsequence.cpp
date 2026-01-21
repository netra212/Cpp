#include <iostream>
using namespace std;

// Q. Finding the subsequences of the given arrays.
void subsequence(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> &temp)
{
    //  Stopping Condition or Base case.
    if (index == n)
    {
        ans.push_back(temp); // temp is 1D array and ans is 2D array.
        return;
    }

    //  If Not taken.
    subsequence(arr, index + 1, n, ans, temp);

    // If taken.
    temp.push_back(arr[index]);
    subsequence(arr, index + 1, n, ans, temp);
}

int main()
{
    int arrr[] = {1, 2, 3, 4, 5};
    vector<vector<int>> ans; // to store the final answer.
    vector<int> temp;
    int n = 5; // number of elements in the arrays.
    subsequence(arrr, 0, n, ans, temp);

    // Now, Print the 2-D vector.
}
