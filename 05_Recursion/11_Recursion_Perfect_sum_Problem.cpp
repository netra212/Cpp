#include <iostream>
using namespace std;

// Q. Find the Perfect Sum Problem.
int recursionPerfectSumProblem(int arr[], int index, int n, int sum)
{
    /**
     * Find the total number of subset, that sum are equal to 8.
     * Example: [2, 5, 6, 1], sum = 8
     * ans: [2, 5, 1], [6, 1], total number of subset are 2.
     *
     */

    if (index == n)
    {
        return sum == 0;
    }

    // Not Included.
    return recursionPerfectSumProblem(arr, index + 1, n, sum) + recursionPerfectSumProblem(arr, index + 1, n, sum - arr[index]);
    ;
}

// Q. Target sum repeat it ion.
int targetSumRepeat(int arr[], int index, int n, int sum)
{
    /**
     * [2, 3, 4], sum = 6
     * how many times, sum 6 can be achieved. ?
     * One number can be used multiple times but order should be maintain.
     * Like..
     * {2, 3} - no
     * {2, 4} - yes
     * {2, 2, 3} - no
     * {2, 2, 2} - yes
     * {3, 3} - yes
     * ans -> 3
     */
    if (sum == 0)
    {
        return 1;
    }
    if (index == n || sum < 0)
    {
        return 0;
    }

    return targetSumRepeat(arr, index + 1, n, sum) + targetSumRepeat(arr, index + 1, n, sum - arr[index]);
}

// main function.
int main()
{
    int arr[] = {1, 4, 3, 6, 5};
    int sum = 8;
    int n = 5;
    cout << recursionPerfectSumProblem(arr, 0, n, sum);
}
