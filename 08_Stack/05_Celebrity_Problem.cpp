#include <iostream>
using namespace std;

// Q. The Celebrity Problem.
int theCelebrityProblem(vector<vector<int>> &M, int n)
{
    /**
     * - - - - -
     * | 0 1 0 1 1
     * | 0 0 0 1 1
     * | 0 1 0 1 0
     * | 0 0 0 0 0
     * | 1 0 1 1 0
     * n-people
     * Let's suppose, mahesh babu come into my house, we all know him because he is a celebrity but mahesh babu did not know me and my family which means, we know he is celebrity and he does not know us. so this scenarios exactly resembles the celebrity problem.
     *
     */
    stack<int> st;
    for (int i = n - 1; i >= 0; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        // first person know second person but second person does not know first person.
        if (M[first][second] && !M[second][first])
        {
            st.push(second);
        }
        // second person does not know but second person know the first person.
        else if (!M[first][second] && M[second][first])
        {
            st.push(first);
        }
    }

    if (st.empty())
    {
        return -1;
    }
    int num = st.top();
    st.pop();
    int row = 0, col = 0;
    for (int i = 0; i < n; i++)
    {
        row += M[num][i];
        col += M[i][num];
    }

    return row == 0 & col == n - 1 ? num : -1;
}

//
int main()
{
    //
}