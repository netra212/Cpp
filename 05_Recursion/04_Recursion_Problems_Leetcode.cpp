/**
 * Solving leetcode Problems based on recursions.
 */

// Q. finding the fibonacci series.
int fibonacciSeries(int n)
{
    /**
     * Fibonacci number is calculated by adding the sum of n-1 + n-2 + .... so on.
     * 0 1 1 2 3 5 8 13 21 34 55
     *
     * If I need to calculate the 8th fibonacci number, then I will have to calculate the 7th and 6th number and by adding both of them, I can find the fibonacci number.
     *
     * Approach:
     * fib(0) = 0
     * fib(1) = 1
     * fib(2) = fib(0) + fib(1)
     * fib(3) = fib(2) + fib(1)
     * fib(4) = fib(3) + fib(2)
     * ..........................
     * fib(n) = fib(n-1) + fib(n-2)
     */
    if (n <= 1)
    {
        return n;
    }
    int ans = fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
    return ans;
}

// Q. Nth stairs.
// total numbers of ways required to reach the top of the stairs.
int totalWays(int n)
{
    /**
     * Let's suppose, n = 5, means I have to reach at the 5th stair which is top of stairs. Here, I have to find out the how many ways I can reach at the tops.
     *
     * **Approachs**
     *
     * Way 1: 1 step + 1 step + 1 step + 1 step + 1 step
     * Way 2: 1 step + 1 step + 1 step + 2 step
     * Way 3: 1 step + 1 step + 2 step + 1 step
     * Way 4: 1 step + 2 step + 1 step + 1 step
     * Way 5: 1 step + 2 step + 2 step
     * Way 6: 2 step + 1 step + 1 step + 1 step
     * Way 7: 2 step + 1 step + 2 step
     * Way 8: 2 step + 2 step + 1 step
     *
     * suppose,
     * Let, n = 1, 1 Way
     * total methods: 1
     * total ways or steps:    2
     *
     * n = 2
     * total methods: 2
     * total ways or steps:
     *      1 step + 1 step,
     *      2 step
     *
     * n = 3
     * total method: 3
     * total steps or ways:
     *      1 step + 1 step + 1 step
     *      1 step + 2 step
     *      2 step + 1 step
     *
     * n = 4
     * total method: 5
     * total steps or ways:
     *      1 step +  1 step +  1 step +  1 step
     *      1 step + 1 step + 2 step
     *      1 step + 2 step + 1 step
     *      2 step + 1 step + 1 step
     *      2 step + 2 step
     */
    if (n <= 1)
    {
        return 1;
    }
    return totalWays(n - 1) + totalWays(n - 2);
}

// Q. GCD of two Numbers.
void greatestCommandDivisor(int a, int b)
{
    /**
     * num1 = 18
     * num2 = 48
     * Find the GCD of above two numbers.
     *
     * (18, 48)
     * (48, 18) (48 as same, mode of 18 & 48)
     * (18, 12) (18 as same, mode of 48 & 12)
     * (12, 6) (12 as same, mode of 18 & 12)
     * (6, 0) (6 as same, mode of 12 & 6)
     */
    if (b == 0)
    {
        cout << a;
        return;
    }
    return greatestCommandDivisor(b, a % a);
}

//
#include <iostream>
using namespace std;

int main()
{
    //
}
