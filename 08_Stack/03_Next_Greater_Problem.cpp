#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q. Next Greater Element. or the Nearest greater on right.
vector<long long> nextGreaterElement(vector<long long> v1, int n)
{
    /**
     * Nearest greater on the right side.
     *
     */
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v1[j] > v1[i])
            {
                ans[i] = v1[j];
                break;
            }
        }
    }
    return ans;
}

// More optimized way of solving above question.
vector<long long> nextGreaterElement2(vector<int> &arr, int n)
{
    vector<long long> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;

    // Another methods.
    // stack<int> st1;
    // vector<long long> ans1(n, -1);
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     while (!st.empty() && arr[st.top()] < arr[i])
    //     {
    //         st.pop();
    //     }
    //     if (!st.empty())
    //     {
    //         ans1[i] = arr[st1.top()];
    //     }
    //     st.push(i);
    // }
    // return ans1;
}

// Q. Next smaller Elements on right side.
vector<int> nextSmallerElementOnRightSide(vector<int> arr1, int n)
{
    stack<int> st;
    vector<int> ans1(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr1[st.top()] > arr1[i])
        {
            ans1[st.top()] = arr1[i];
            st.pop();
        }
        st.push(i);
    }
    return ans1;
}

// Q. Smallest Number on Left.
vector<int> smallestNumberLeft(vector<int> arr2, int n)
{
    stack<int> st2;
    vector<int> ans2(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st2.empty() && arr2[st2.top()] > arr2[i])
        {
            ans2[st2.top()] = arr2[i];
            st2.pop();
        }
        st2.push(i);
    }
    return ans2;
}

// Q. Nearest Greatest Number in Left.
void findNearestGreatestNumberInLeft()
{
    //
}

// Q. Stock Span Problem.
vector<int> stockSpanProblem(vector<int> stockPrice, int n)
{
    /**
     *
     * stockPrice = [100, 80, 55, 70, 60, 75, 85]
     * Find all the stock prices which is lesser than 75 stock price.
     * Problem is similar to Next Greatest on Left side.
     *
     */
    stack<int> st;
    vector<int> ans(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && stockPrice[i] > stockPrice[st.top()])
        {
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = st.top() + 1;
        st.pop();
    }
    return ans;
}

//
int main()
{
    //
}
