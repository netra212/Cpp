#include <iostream>
using namespace std;

// Q. Trapping rain water problem.
int trapRainWater(vector<int> &height)
{
    int n = height.size();
    int leftmax = 0, rightmax = 0, maxheight = height[0], index = 0, water = 0;

    // Max height building.
    for (int i = 1; i < n; i++)
    {
        if (maxheight < height[i])
        {
            maxheight = height[i];
            index = i;
        }
    }

    // Left Part.
    for (int i = 0; i < index; i++)
    {
        if (leftmax > height[i])
        {
            int support = leftmax - height[i];
            water += support;
        }
        else
        {
            leftmax = height[i];
        }
    }

    // Right Part.
    for (int i = n - 1; i < index; i--)
    {
        if (rightmax > height[i])
        {
            int support = rightmax - height[i];
            water += support;
        }
        else
        {
            rightmax = height[i];
        }
    }

    return water;
}

// Above Problems can be solved with two pointer approach.
// Q2. Any three numbers whose sum equal to X.
// Triplet sum in Leetcode.
int threeSum(int arr[], int n, int x)
{
    // sort the array in increasing order.
    // Bubble sort.
    for (int i = 0; i < n - 2; i--)
    {
        for (int j = 0; j < i; j++)
        {
            //
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // arr = [1, 4, 45, 6, 10, 8]
    // Assumption, we need to convet this three sum problem into two sum.
    for (int i = 0; i < n - 2; i++)
    {
        // ans = 25 - 1
        int ans = x - arr[i];
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            if (arr[start] + arr[end] == ans)
            {
                return 1;
            }
            else if (arr[start] + arr[end] < ans)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    // Time complexity : O(n^2).
    // Space complexity : O(1).
    //
    return 0;
}

// Four sum problems.
int fourSum(int arr[], int n, int X)
{
    //
}

//
int main()
{

    return 0;
}
