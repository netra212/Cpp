#include <iostream>
using namespace std;

class Solution
{
    int minElement;
    /** store original value */
    stack<int> st1;
    /** store minimum value */
    // stack<int> st2;
    // % -> gives original element.
    // /(divide) -> gives minimum element.
public:
    /** returns min element from stack */
    int getMin()
    {
        if (st1.empty())
        {
            return -1;
        }
        else
        {
            return st1.top() % 101;
        }
    }

    /** returns poped element from stack */
    int pop()
    {
        if (st1.empty())
        {
            return -1;
        }
        else
        {
            int element = st1.top() / 101;
            st1.pop();
            // st2.pop();
            return element;
        }
    }

    /** push element x into the stack */
    void push(int x)
    {
        if (st1.empty())
        {
            // original * 101 + minimum value till now which is x.
            st1.push(x * 101 + x);
            // st2.push(x);
        }
        else
        {
            st1.push(x * 101 + min(x, st1.top() % 101));
            // st2.push(min(st2.top(), x));
        }
    }
    /** NOTE: In order to store two number at same place then we have to use the % (modulus operator).*/
};

// NEED TO RE-WATCHED THIS LECTURE.
// Maximum of minimum for every window size.
vector<int> MaximumOfMinimumForEveryWindowsize(vector<int> &arr, int n)
{
    /**
     * [10, 20, 15, 50, 10, 70, 30]
     * k = 3,
     * {10, 20, 15} -> 10 (minimum for every 3 window size)
     * {20, 15, 50} -> 15
     * {15, 50, 10} -> 10
     * {50, 10, 70} -> 10
     * {10, 70, 30} -> 10
     * so, we required vector to store answer.
     * answer = []
     * arr =  [10, 20, 15, 50, 10, 70, 30]
     * for k = 1,
     *  {10}, {20}, {15}, {50}, {10}, {70}, {30}
     * for k = 2,
     * {10, 20} -> 10 (min), {20, 15} -> 20 (min), {15, 50} -> 15 (min), {50, 10} -> 10 (min), {10, 70} -> 10 (min), {70, 30} -> 30 (Min)
     * Minimum of 2 windows: 10, 20, 15, 10, 10, 30
     * Now, the maximum of above minimum of window size is:  30
     * Final Answer is: 30
     */
    // FIRST APPROACH N^3.
    // vector<int> ans(n, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - 1; j++)
    //     {
    //         int num = INT_MAX;
    //         for (int k = j; k < i + 1; k++)
    //         {
    //             num = min(num, arr[k]);
    //         }

    //         ans[i] = max(ans[i], num);
    //     }
    // }
    // return ans;

    // OPTIMIZED WAY.
}

//
int main()
{
    //
}