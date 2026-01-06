/**
 *
 * Kadane's Algorithm
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q. Prefix(starting from begining) and Suffix (starting from last) Sum
void prefixSum(int arr[], int n)
{
    vector<int> prefixsum(n);
    prefixsum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixsum[i] = arr[i - 1] + arr[i];
    }
}

// Q. Suffix sum
void suffixSum(int arr[], int n)
{
}

// Q. Subarray Problem.
void printAllSubArray(int arr[], int n)
{
    /*
     *  int arr[] = {4, 3, 7, 2}
     * 1 size subarray = [4], [3], [7], [2] -> n
     * 2 size subarray = [4,3], [3,7], [7,2] -> n - 1
     * 3 size subarray = [4, 3, 7], [3,7,2] -> n-2
     * 4 size subArray = [4, 3, 7, 2] -> n-3
     * Question. print all the subArray in the above arrays.
     */
}

// Q. Divide array in 2 subarray with equal sum.
int divideArrayIn2SubarrayWithEqualSum(int arr[], int n)
{
    // int arr[] = {3, 4, -2, 5, 8, 20, -10, 8}
    // Assumption:
    // totalSum dekhii prefix laii minus gardaii janu paryo.
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    int prefix = 0;
    for (int i = 0; i < n - 1; i++)
    {
        prefix = prefix + arr[i];
        int ans = totalSum - prefix;
        if (ans == prefix)
        {
            return 1;
        }
    }
    return 0;
}

// Q. Largest sum Contiguous subarray.
// Largest sum of subarray.
long long LargestSumContiguousSubArray(int arr[], int n)
{
    /*
     *  int arr[] = {4, 3, 7, 2}
     * 1 size subarray = [4], [3], [7], [2] = 15
     * 2 size subarray = [4,3], [3,7], [7,2] = sum => 7 + 10 + 9 => 26
     * 3 size subarray = [4, 3, 7], [3,7,2] = sum => 14 + 12 => 26
     * 4 size subArray = [4, 3, 7, 2] = sum => 16
     * maximum subarray =
     */
    // This below shows the implementation of the kadane's algorithm.
    long long maxi = INT_MIN, prefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        maxi = max(prefix, maxi);
        if (prefix < 0)
        {
            prefix = 0;
        }
        return maxi;
    }
}

// Q. Maximum Difference between 2 element.
int maxDifferenceBetn2Elements(int arr[], int n)
{
    int ans;
    return ans;
}

//
int main()
{
    int arr[] = {6, 4, 5, -3, 2, 8};
}