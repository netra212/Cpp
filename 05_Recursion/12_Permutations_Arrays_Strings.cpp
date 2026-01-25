#include <iostream>
using namespace std;

// Q. Find the permutations of a given arrays.
// NEED REVISION THIS WITH COPY AND PEN.
vector<vector<int>> permutationsOfGivenArrays(int arr[], vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
{
    /**
     * Example:-
     * arr = {1, 2, 3}
     * Here is a catch, all the numbers will be distinct.
     *
     * {1, 2, 3}
     * {1, 3, 2}
     * {2, 3, 1}
     * {2, 1, 3}
     * {3, 1, 2}
     * {3, 2, 1}
     *
     */

    //  Base condition.
    if (visited.size() == temp.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            temp.push_back(arr[i]);
            permutationsOfGivenArrays(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }

    return ans;
}

// Find the permutation of the given arrays without taking any space.
vector<vector<int>> permutationArrayWithoutExtraspace(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        permutationArrayWithoutExtraspace(arr, ans, index + 1);
        swap(arr[i], arr[index]); // Pahile kai position ma ferii return gareko.
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(3, 0);
    permutationsOfGivenArrays(arr, ans, temp, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
