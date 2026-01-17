/**
 * This code is the part of the Recursion: Factorial of N Numbers.
 */
#include <iostream>
using namespace std;

// Q. Calculating the factorial of a numbers.
int factorialNumber(int n)
{
    /**
     * Approach:
     * fact(1) = 1
     * fact(2) = 2 * fact(1)
     * fact(3) = 3 * fact(2)
     * fact(4) = 4 * fact(3)
     * ......  = ...........
     * fact(n) = n * fact(n-1) <-- Formula.
     * OR..
     * fact(1) = 1
     * fact(2) = 2 * fact(1) => 2 * 1 => 2
     * fact(3) = 3 * fact(2) => 3 * 2 => 6
     * fact(4) = 4 * fact(3) => 4 * 6 => 24
     * fact(5)  = 5 * fact(4) => 5 * 24 => 120
     */

    // BASE CASE.
    if (n == 0)
    {
        return 1;
    }
    int ans = n * factorialNumber(n - 1);
    return ans;
}

// Q. sum of N Numbers.
int sumNNumbers(int m)
{
    /**
     * Approaches to solve the problems.
     * sum(1) = 1
     * sum(2) = 2 + sum(1)
     * sum(3) = 3 + sum(2)
     * sum(4) = 4 + sum(3)
     * ....................
     * sum(n) = n + sum(n-1)
     */
    if (m == 1)
    {
        return 1;
    }
    return m + sumNNumbers(m - 1);
}

// Q. Power of 2.
int calculatePowerOf2(int num, int n)
{
    // 2^5
    /***
     * num  n   ans
     * 2    5   32
     * 2    4   16
     * 2    3   8
     * 2    2   4
     * 2    1   1
     * stopping or base condition.
     * pow(2, 1) = 2
     * pow(2, 2) = 2 * pow(2, 1)
     * pow(2, 3) = 2 * pow(2, 2)
     * pow(2, 4) = 2 * pow(2, 3)
     * .........................
     * pow(2, n) = 2 * pow(2, n-1)
     * Let's visualize.
     * 2^n = 2 * 2^n-1
     * 2^n-1 = 2 * 2^n-2
     * 2^n-2 = 2 * 2^n-3
     *
     */
    if (n == 0)
    {
        return 1;
    }
    if (num == 1)
    {
        return num;
    }
    return num * calculatePowerOf2(num, n - 1);
}

// Q. Sum of Sqaure of N Natural Numbers.
int sumOfNNaturalNumbers(int n)
{
    /**
     * SqSum(1) = 1
     * SqSum(2) = 2^2 + SqSum(1)
     * SqSum(3) = 2^3 + SqSum(2)
     * SqSum(4) = 2^4 + SqSum(3)
     * ..........................
     * SqSum(n) = 2^n + SqSum(n-1)
     * NOTE: In this scenarios, N should always greater than 1.
     */
    if (n == 1)
    {
        return 1;
    }
    return n * n + sumOfNNaturalNumbers(n - 1);
}

//
int main()
{
    int n = 5;
    if (n <= 0)
    {
        cout << "Factorial is not possible" << endl;
    }
    int m = 5;
    if (m <= 0)
    {
        cout << "Adding 0 to the previous numbers does not contribue anything so " << endl;
    }
    factorialNumber(n);
    sumNNumbers(m);
    // Power to be calculated.
    int num = 2;
    calculatePowerOf2(num, n);
}
