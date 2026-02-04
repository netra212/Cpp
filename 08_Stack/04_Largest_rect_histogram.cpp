#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Q. Find the Largest Rectangle Histogram.
int findLargestRectHistogram(vector<int> &height)
{
    int n = height.size();
    vector<int> right(n);
    vector<int> left(n);
    stack<int> st;

    // Find Next smallest on the right.
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[st.top()] > height[i])
        {
            // Update the index on the right
            right[st.top()] = i;
            st.pop();
        }
    }

    // Empty stack.
    while (!st.empty())
    {
        right[st.top()] = n;
        st.pop();
    }

    // Find next smallest on the left.
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && height[st.top()] > height[i])
        {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // Empty the stack
    while (!st.empty())
    {
        left[st.top()] = -1;
        st.pop();
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, height[i] * (right[i] - left[i] - 1));
    }
    return ans;

    // Another methods.
    stack<int> st1;
    int ans1 = 0;
    int index;
    int n = height.size();
    for (int i = 0; i < n; i++)
    {
        while (!st1.empty() && height[st1.top()] < height[i])
        {
            index = st1.top();
            st1.pop();

            if (!st1.empty())
            {
                ans1 = max(ans1, height[index] * (i - st1.top() - 1));
            }
            else
            {
                ans1 = max(ans1, height[index] * i);
            }
        }
        st1.push(i);
    }
    // Empty the stack.
    while (!st1.empty())
    {
        index = st1.top();
        st1.pop();

        if (!st1.empty())
        {
            ans1 = max(ans1, height[index] * (n - st.top() - 1));
        }
        else
        {
            ans1 = max(ans1, height[index] * n);
        }
    }
    return ans1;
}

// Q. Maximum Rectangle.
int maximalRectangle(vector<vector<char>> &matrix)
{
    /**
     * 1 0 1 0 0
     * 1 0 1 1 1
     * 1 1 1 1 1
     * 1 0 0 1 0
     * calculate the largest rectangle containing the areas.
     *
     */
    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> heights(col, 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '0')
            {
                heights[j] = 0;
            }
            else
            {
                heights[j]++;
            }
        }
        ans = max(ans, findLargestRectHistogram(heights));
    }
    return ans;
}

int main()
{
    //
}