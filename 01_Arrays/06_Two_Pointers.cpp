/**
 * Two Pointers in Cpp.
 *
 */
#include <iostream>
using namespace std;

// Q1. Segregate 0 AND 1.
void segregate0And1(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (arr[start] == 0)
        {
            start++;
        }
        else
        {
            if (arr[end] == 0)
            {
                swap(arr[start], arr[end]);
                start++, end--;
            }
            else
            {
                end--;
            }
        }
    }
}

// Q2. Two sum
void twoSum(int arr[], int n, int target)
{
    // int arr = {2, 7, 11, 15, 27}
    vector<int> ans;
    int start = 0, end = n - 1;
    while (start <= end)
    {
        if (arr[start] + arr[end] == target)
        {
            cout << "first number: " << start << "2nd number: " << end << " ";
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            break;
        }
        else if (arr[start] + arr[end] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    // If the array is sorted, then i could use the binary search.
    // 2, 7, 11, 15, 27.
}

// Q3. Pair with Given Difference.
int pairWithGivenDifference(int arr[], int n, int target)
{
    // arr = [5, 10, 3, 2, 50, 80]
    // Difference = 45
    int start = 0, end = n - 1;
    vector<int> ans;
    while (start <= end)
    {
        if (arr[start] - arr[end] == target)
        {
            cout << "first number: " << start << "2nd number: " << end << " ";
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            break;
        }
        else if (arr[start] - arr[end] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
}

//
int main()
{
    int arr[] = {1, 0, 1, 0, 1, 0};
    int n = 6;
    segregate0And1(arr, n);
}
