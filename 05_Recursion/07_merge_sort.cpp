#include <iostream>
using namespace std;

// Merging two arrays.
// time complexit of merge sort is n(logn).
void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    // left -> Points towards left arrays.
    // right -> Point towards right arrays.
    int left = start, right = mid + 1, index = 0;
    while (left <= mid & right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] == arr[left];
            index++, left++;
        }
        else
        {
            temp[index] == arr[right];
            index++, left++;
        }
    }

    // If any elements remaning then paste the elements into temp or if left array is not empty.
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }

    // If any elements remamining then paste the elements into temp or if right array is not empty.
    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }

    index = 0;

    // Now, copying the elements into original arrays.
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, end++;
    }
}

// Q. Merge sort or Divide and Merge.
void mergeSort(int arr[], int start, int end)
{
    if (start == end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid + 1);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    //
}
