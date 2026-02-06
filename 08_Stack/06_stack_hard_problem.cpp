#include <iostream>
using namespace std;

class Solution
{
    int minElement;
    /** store original value */
    stack<int> st1;
    /** store minimum value */
    stack<int> st2;
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

//
int main()
{
    //
}