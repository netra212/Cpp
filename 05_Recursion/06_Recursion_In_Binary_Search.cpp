/**
 * Recursion in Binary search.
 */
#include <iostream>
using namespace std;

// Q. Implementing linear search with recursion.
bool linearSearch(int arr[], int x, int index, int N)
{
    //
    if (index == N)
    {
        return 0;
    }

    if (arr[index] == x)
    {
        return 1;
    }
    return linearSearch(arr, x, index + 1, N);
}

// Q. Binary search.
bool binarySearch(int arr[], int start, int end, int x)
{
    // time taken: n(logn)
    /**
     * arr = [3, 8, 11, 15, 20, 22]
     * In BS, start, mid, end.
     *
     */

    if (start >= end)
    {
        return 0;
    }
    int mid = start + end - start / 2;

    if (arr[mid] == x)
    {
        return 1;
    }
    else if (arr[mid] < x)
    {
        return binarySearch(arr, mid + 1, end, x);
    }
    else
    {
        return binarySearch(arr, start, mid - 1, x);
    }
}
