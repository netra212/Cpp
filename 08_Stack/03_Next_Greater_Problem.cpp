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
vector<long long> nextGreaterElement2(vector<long long> &arr, int n)
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
vector<long long> *nextSmallerElementOnRightSide(vector<long long> arr1, int n)
{
    //
}

//
int main()
{
    //
}