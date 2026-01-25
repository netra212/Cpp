#include <iostream>
using namespace std;

// Q. Find Permutation where duplicate elements may be present and the numbers present in the arrays lies between -10 <= num <= 10.
// Given a collection of numbers, nums, that might contains duplicates, return all possible unique permutations in any order.
void permutationWithDuplications(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    vector<bool> use(21, 0); // since numbers from -10 <= 10.

    if (index == arr.size())
    {
        ans.push_back(arr);
    }
    for (int i = index; i < arr.size(); i++)
    {
        // 1 + 10 => 11 go to 11 index check if that particular element is equal to zero or not,
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[index], arr[i]);
            permutationWithDuplications(arr, ans, index + 1);
            swap(arr[index], arr[i]); // Bringing back to original position.
            use[arr[i] + 10] = 1;
        }
    }
}

// Q. Ways to sum N.
int waysToSumN(int arr[], int m, int sum)
{
    /**
     * Example: [1, 5, 6]
     * How many ways we can achieve the sum equal to 7.
     * Order matters.
     * Like...
     * 1 + 1 + 1 + 1 + 1 + 1 + 1
     * 1 + 1 + 5
     * 1 + 6
     * 1 + 5 + 1
     * 5 + 1 + 1
     * 6 + 1
     * Ans: total number of ways that sum equal to 7.
     */
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += waysToSumN(arr, m, sum - arr[i]);
    }
    return ans;
}

int main()
{
    //
}
