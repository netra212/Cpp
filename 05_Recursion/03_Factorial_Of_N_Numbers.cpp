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
     * fact(n) = n * fact(n-1)
     */
    // BASE CASE.
    if (n <= 0)
    {
        return -1;
    }
    int ans = n * factorialNumber(n - 1);
    return ans;
}

int main()
{
    int n = 5;
    factorialNumber(n);
}