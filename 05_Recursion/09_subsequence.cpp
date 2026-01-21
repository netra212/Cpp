#include <iostream>
using namespace std;

// Q. Finding the subsequences of the given arrays.
vector<vector<int>> subsequence(int arr[], int index, int n, vector<vector<int>> &ans, vector<int> &temp)
{
    //  Stopping Condition or Base case.
    if (index == n)
    {
        ans.push_back(temp); // temp is 1D array and ans is 2D array.
        return;
    }

    //  If Not taken.
    subsequence(arr, index, n, ans, temp);

    // If taken.
    temp.push_back(arr[index]);
    subsequence(arr, index + 1, n, ans, temp);
    temp.pop_back();
    return ans;
}

// Q. Find subsequences of the given string. 'abc'.
vector<string> subsetString(string &s, int index, int n, vector<string> &ans, string &temp)
{
    // This is similar to the above problem only data types are different.
    //  Stopping Condition or Base case.
    if (index == n)
    {
        ans.push_back(temp); // temp is 1D array and ans is 2D array.
        return;
    }

    //  If Not taken.
    subsetString(s, index, n, ans, temp);

    // If taken.
    temp.push_back(s[index]);
    subsetString(s, index + 1, n, ans, temp);
    temp.pop_back();
    return ans;
}

// Q. Generate Parenthesis.
vector<string> generateParenthesis(int n, int leftParenthesis, int rightParenthesis, vector<string> &ans, string &temp)
{
    /**
     *
     * For n = 2, generate how many parenthesis can be formed when n = 2.
     * Like ans =  [()(), (())]
     * for n = 3,
     * Ans = ((())), (())(), ()(()), (()()), ()()()
     *
     * Let suppose,
     * for n = 2
     * 2 left parenthesis, 2 right parenthesis will be there.
     *
     * for n = 3,
     * 3 left parenthesis, 3 right parenthesis will be there.
     * for valid parenthesis, numberOfOpeningBracket i.e.., [ ( ]>= numberOfClosingBracket i.e.., [ ) ]
     *
     * For Example,
     * n = 3, L = 0, R = 0
     * When the number of right parenthesis is greater than only add the left parenthesis.
     *
     */

    //  Stopping Condition.
    if (leftParenthesis + rightParenthesis == 2 * n)
    {
        ans.push_back(temp);
        return;
    }
    // Add Left Parenthesis.But Condition of adding Left Parenthesis.if (leftParenthesis < n)
    {
        temp.push_back('(');
        generateParenthesis(n, leftParenthesis + 1, rightParenthesis, ans, temp);
        temp.pop_back();
    }

    // Add Right Parenthesis.
    if (rightParenthesis < leftParenthesis)
    {
        temp.push_back(')');
        generateParenthesis(n, leftParenthesis, rightParenthesis + 1, ans, temp);
        temp.pop_back();
    }
    return ans;
}

int main()
{
    int arrr[] = {1, 2, 3};
    vector<vector<int>> ans; // to store the final answer.
    vector<int> temp;
    int n = 5; // number of elements in the arrays.
    subsequence(arrr, 0, n, ans, temp);

    // Now, Print the 2-D vector.
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // For string 'abc'
    string s = "abc";
    vector<string> ans1;
    string temp1;
    subsetString(s, 0, s.size(), ans1, temp1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
