#include <iostream>
#include <stack>
using namespace std;

// Q. Write a function that reverse a string. The input string is given as an array of characters.
void reverseString(vector<char> v)
{
    /**
     *
     * int arr[] = {h, e, l, l, o}
     * Appraoch:
     * First create an stack with array data type, and push all the elements into the stack, then fetch every element from the top then we will get the reversed arrays.
     *
     */
    stack<char> st; // Creating a stack with character type.
    for (int i = 0; i < v.size(); i++)
    {
        st.push(v[i]); // inserting an element into stack.
    }
    int i = 0;
    while (!st.empty())
    {
        // st.top() always fetch the top element from the stack.
        v[i] = st.top();
        i++;
        st.pop();
    }
}

// Q. Insert a Button.
stack<int> insertAtAButtom(stack<int> st, int x)
{
    /**
     * Insert x = 2 at the button of the stack.
     * int x = 2.
     * Approach:
     * First, create a new stack called temp, empty the given stack named st, then insert first x = 2 element at the given stack then again insert the other previous element of the stack.
     */
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }

    return st;
}

// Q. Make the arrays beautiful.
// When we have an adjacent element, this should be either non-negative or both negative, if that so they can be together.
vector<int> makeArraysBeautiful(vector<int> &arr)
{
    /**
     *
     * vector<int> v1 = [2, 3, 5, -4, 6, -2, -8, 9]
     *
     */
    stack<int> st; // creating an stack similar to vector datatype.
    for (int i = 0; i < arr.size(); i++)
    {
        // stack can be empty.
        if (st.empty())
        {
            st.push(arr[i]);
        }
        // non negative number.
        else if (arr[i] >= 0)
        {
            // Non Negative
            if (st.top() >= 0)
            {
                st.push(arr[i]);
            }
            else
            { // if Negative number, remove from stack.
                st.pop();
            }
        }
        else
        {
            // Negative Number.
            if (st.top() < 0)
            {
                // Pushing negative number.
                st.push(arr[i]);
            }
            else
            {
                st.pop();
            }
        }
    }
    vector<int> ans(st.size());
    int i = st.size() - 1;
    while (!st.empty())
    {
        ans[i] = st.top();
        i--;
        st.pop();
    }
    return ans;
}

// Q. String Manipulation.
// Remove the same string if present at the adjancent element.
int removeConsecutiveSame(vector<string> v)
{
    /**
     * {ab, ac, da, da, ac, db, ea}
     * According to the question, we need to remove an da, da from the string array.
     * so ans is like {ab, db, ea}
     */
    stack<string> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
        {
            s.push(v[i]);
        }
        else if (s.top() == v[i])
        {
            s.pop();
        }
        else
        {
            s.push(v[i]);
        }
    }
    //
    return s.size();
}

// Q. Check either parenthesis is valid or not.
bool checkParenthesIsValidOrNot(string str)
{
    /**
     * str = ((())())
     */
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}

// Q. minimum number of parenthesis required to add to make valid parenthesis.
int minimumAddToMakeValidParenthesis(string s)
{
    stack<char> st;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                count++;
            }
            else
            {
                st.pop();
            }
        }
    }
    return count + st.size();
}

// Q. Valid Parenthesis.
int validParenthesis(string s)
{
    /**
     * s = (()){}[()]
     * Check either the above string is valid or not.
     */
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // Opening Brackets.
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        // Closing Bracket.
        else
        {
            // Check either stack is empty or not.
            if (st.empty())
            {
                return 0;
            }
            else if (s[i] == ')')
            {
                if (st.top() != '(')
                {
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == '}')
            {
                if (st.top() != '{')
                {
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                if (st.top() != '[')
                {
                    return 0;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    return st.empty();
}

// Q. Background string compare.
void backgroundStringCompare(string s1, string s2)
{
    /**
     * str1 = ab#c
     * str2 = ad#c
     * Where, # -> represent Backspace.
     * If we saw the #, then we need to remove the one character from behind, then compare the two string if matched or not.
     */
}

// Q. Print Bracket Number.
vector<int> printBracketNumber(string s)
{
    /***
     * s = (aa(bdc))p(de)
     *
     */
    int count = 0;
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++)
    {
        // Opening Bracket and Closing Bracket.
        if (s[i] == '(')
        {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        // Closing Bracket.
        else if (s[i] == ')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}

/**
 *
 *  Q. Get minimum at pop.
 *
 */
stack<int> push(int arr[], int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) // initially stack will be empty.
        {
            st.push(arr[i]);
        }
        else
        {
            st.push(min(arr[i], st.top())); // only push the minimum elements.
        }
    }
    return st;
}
void getMinimumAtPop(stack<int> s)
{
    /**
     * [2, 1, 3, 5, 0, 6]
     */
    while (!s.empty())
    {
        cout << s.top() << " " << endl;
        s.pop();
    }
}

//
int main()
{
    string str = "((((()))))())";
    cout << checkParenthesIsValidOrNot(str) << endl;
    return 0;
}