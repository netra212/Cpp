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

//
int main()
{
    //
}