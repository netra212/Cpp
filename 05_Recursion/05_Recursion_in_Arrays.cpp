/**
 * Recursion in Arrays.
 */
#include <iostream>
using namespace std;

// Q. Print array.
void printArrays(int arr[], int index, int n)
{
    if (index == n)
    {
        return;
    }
    cout << arr[index];
    printArrays(arr, index + 1, n);
}

// Q. sum of all element.
int sumAllElements(int arr[], int index, int n)
{
    //
    if (index == n)
    {
        return 0;
    }
    return arr[index] + sumAllElements(arr, index + 1, n);
}

// Q. finding the Mininum element in the array.
int minElement(int arr[], int index, int n)
{
    //
    if (index == n - 1)
    {
        return arr[index];
    }
    return min(arr[index], minElement(arr, index + 1, n));
}

//
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printArrays(arr, 0, 5);
}
