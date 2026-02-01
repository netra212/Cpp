#include <iostream>
#include <stack>
using namespace std;

/**
 * ------ STACK ------
 * It is a linear data structure, in which insertion and deletion only allowed at the end, called the top of the stack.
 *
 * When we defined a stack as an abstract data types, then we are only interested in know the stack operations.
 *
 * Operations in stack:
 * Push :
 * Pop :
 * Top lor peek : tell the what element is present in particular index.
 * issize :
 * isempty :
 *
 * First in First Out.
 * First in Last Out.
 * Last in Last Out.
 * Last in First Out -> stack
 *
 */

//  Implementation of stack using Arrays.
class Stack
{
    int *arr;
    int size;
    int top;

public:
    bool flag;
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[s];
        flag = 1;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " into the stack \n";
            flag = 0;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow." << endl;
        }
        else
        {
            top--;
            cout << "Element " << arr[top + 1] << " Popped succesfully." << endl;
            if (top == -1)
            {
                flag = 1;
            }
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int isSize()
    {
        return top + 1;
    }
};

// Implementation stack using LinkedList.
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class StackNode
{
    Node *top;
    int size; // tell the actual size of stack.

public:
    StackNode()
    {
        top = NULL;
        size = 0; // Initially size of stack is zero.
    }

    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "stack Overflow. " << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
            size++;
            cout << "Pushed  " << value << " into the stack " << endl;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow. " << endl;
            return;
        }
        else
        {
            Node *temp = top;
            cout << "Popped " << top->data << " from the stack. " << endl;
            top = top->next;
            delete temp;
            size--;
        }
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool IsEmpty()
    {
        return top == NULL or top == -1;
    }

    int IsSize()
    {
        return size;
    }
};

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Stack stack1(5);
    int value = stack1.isEmpty();
    if (stack1.flag == 0)
    {
        cout << value << endl;
    }
    stack1.push(5);
    stack1.push(6);
    stack1.push(7);

    // stack STL;
    stack<int> s1;
    s1.push(6);
    s1.push(16);
    s1.push(26);
    cout << s1.size() << endl;
    cout << s1.top() << endl;
}