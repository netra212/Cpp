#include <iostream>
using namespace std;

// Q. Find the sum of subset of the given arrays.
vector<int> sumOfSubset(int arr[], int index, int n, int sum, vector<int> &ans)
{
    /**
     * [1, 2, 3]
     *
     */
    if (index == n)
    {
        ans.push_back(sum);
        return;
    }

    // Not Include
    sumOfSubset(arr, index + 1, n, sum, ans);

    // Included
    sumOfSubset(arr, index + 1, n, sum + arr[index], ans);
    return ans;
}

// Q. Find the target sum.
bool targetSum(int arr[], int index, int n, int target)
{
    /**
     * arr = {3, 6, 4, 5}
     * {3, 6, 4} = 13
     *
     */
    // Base or stopping condition.
    if (target == 0)
    {
        return 1;
    }
    if (index == n || target < 0)
    {
        return 0;
    }
    return targetSum(arr, index + 1, n, target) || targetSum(arr, index + 1, n, target - arr[index]);
}

//
int main()
{
    int arr[] = {1, 2, 3, 4};
    vector<int> ans;
    sumOfSubset(arr, 0, 4, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
