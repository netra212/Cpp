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
bool parenthesisValidOrNot(string str)
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

//
int main()
{
    //
}