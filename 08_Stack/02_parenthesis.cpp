#include <iostream>
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
void insertAtAButtom()
{
    /**
     * Insert x = 2 at the button of the stack.
     * int x = 2.
     * Approach:
     * First, empty the stack, then insert first x = 2 element then again insert the other previous element of the stack.
     */
}

//
int main()
{
    //
}