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
    // First find the largest element.
    // Then find the second largest element.
    int firstLargestElement = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstLargestElement)
        {
            firstLargestElement = arr[i];
        }
    }

    // Then Finding the second largest element.
    int secondLargestElement = -1;
    for (int i = 0; i < n; i++)
    {
        // since, we need to calculate the distinct second largest element, so 1st and 2nd largest element should not be same.
        if (arr[i] != secondLargestElement)
        {
            secondLargestElement = max(secondLargestElement, arr[i]);
        }
    }
    return secondLargestElement;
}

// Q4. Missing Number in the arrays.
int missingNumberInArray(int arr[], int n)
{
    // Approaches.
    // First Calculate the sum of all element in an array.
    // 2nd Calculate the sum of n numbers
    // then calculate the difference between them.
    int sumOfArrElement = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sumOfArrElement += arr[i];
    }

    // sum of n number.
    int sumNNumber = n * (n + 1) / 2;
    int ans = sumNNumber - sumOfArrElement;
    return ans;
}

// Q5. Fibonacci Series, Find the 7th element in the Fibonacci series.
void fibonacciSeries()
{
    int n;
    cout << "Enter the number where you want to calculate the fibonacci series up to: " << endl
         << " ";
    cin >> n;
    int arr[1000];
    // first and second element in the fibonacci series is 0 and 1.
    // first = 0;
    // second = 1;

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n - 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n - 1] << " ";
}

// Q6. Rotate Array By 1.
void rotateArrayBy1(int arr[], int n)
{
    // Rotating array element by 1 Position in Clockwise direction.
    // OriginalArray = 2, 7, 4, 11, 5, 8
    // ResultantArray = 8, 2, 7, 4, 11, 5
    int lastElement = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = lastElement;
}

// Passing an Arrays into function.
void passingArraysIntoFunction(int arr[], int n)
{
    //
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// main function.
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
