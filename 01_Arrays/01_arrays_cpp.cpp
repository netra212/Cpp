#include <iostream>
using namespace std;

int sumNElement(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return 0 + sumNElement(n - 1);
}

int main()
{
    // int arr[5] = {2, 3, 1, 7, 8};
    // cout << sizeof(arr) / sizeof(arr[0]) << endl;

    // //
    // int ans = INT_MAX;
    // // Finding the minimum value in the arrays.
    // for (int i = 0; i < 5; i++)
    // {
    //     if (arr[i] < ans)
    //     {
    //         ans = arr[i];
    //     }
    // }

    // Finding the maximum value in the arrays.
    // int ans1 = INT_MIN;
    // for (int i = 0; i < 5; i++)
    // {
    //     if (arr[i] > ans1)
    //     {
    //         ans1 = arr[i];
    //     }
    // }
    // cout << ans1 << endl
    //      << " ";

    // Finding the sum of N elements.
    int n;
    cout << "Enter the n element: " << endl
         << " ";
    cin >> n;
    cout << "The sum of n Element is : " << sumNElement(n) << endl;
    return 0;
}
