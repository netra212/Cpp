#include <iostream>
using namespace std;

// Q1. Search element in an array : GeeksforGeeks
int searchElementInArray(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element Found at this Location: " << i << endl;
            break;
        }
    }
    return -1;
}

// Q2. Reversing an Array.: GeeksforGeeks
int reverseArrayElement(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++, end--;
    }
}

// Q3.Second maximum from the array : GeeksforGeeks
int secondMaxElementFromArray(int arr[], int n)
{
}

int main()
{
    int arr[] = {10, 20, 7, 11, 8, 4};
    int n = 6;

    // Q1. Function Calling..
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 11;

    int index = searchElementInArray(arr, size, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    // Q2. Function Calling...
    reverseArrayElement(arr, n);

    // Print reversed array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Q3.
    return 0;
}