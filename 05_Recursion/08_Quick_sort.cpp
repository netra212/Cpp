/**
 *
 *
 * First Select Pivot element (any element).
 * Quicksort Algorithm Steps:

 * a. Choose a Pivot: Select an element from the array to be the pivot. Common choices are the first, last, middle, or a random element.

 * b. Partition the Array: Rearrange the array so that all elements smaller than the pivot are on its left, and all elements greater than the pivot are on its right. The pivot ends up in its final sorted position.

 * c. Recursive Sorting:

        1. Recursively apply the Quick Sort algorithm to the sub-array to the left of the pivot.

        2. Recursively apply the Quick Sort algorithm to the sub-array to the right of the pivot.

 * d. Base Case: The recursion stops when a sub-array has zero or one element, as it's considered already sorted.

 */
#include <iostream>
using namespace std;

//
int partition(int arr[], int start, int end)
{
    int pos = start;
    for (int i = 0; i <= end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos - 1;
}

//
void quickSort(int arr[], int start, int end)
{
    /**
     * 1. First select the PivotElement then make put every element which is lesser or equal to pivotelement in left, greater element on the right side of the pivot element.
     */

    if (start >= end)
    {
        return;
    }

    // Finding the Position of the PivotElement.
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1); // go to the left part.
    quickSort(arr, pivot + 1, end);   // go to the right part.
}

//
int main()
{
    int arr[] = {10, 3, 4, 1, 5, 6, 3, 2, 11, 9};
    quickSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
