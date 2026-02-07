#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear;
    int size;

public:
    Queue(int n)
    {
        arr = new int[n];
        front = -1, rear = -1;
        size = n;
    }

    // If queue is empty or not.
    bool isEmpty()
    {
        return front == -1;
    }

    // Queue is full or not.
    bool isFull()
    {
        return rear == size - 1;
    }

    // Push element into queue
    void push(int x)
    {
        // Empty
        if (isEmpty())
        {
            cout << "Pushed " << x << " into the Queue\n";
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // Full
        else if (isFull())
        {
            cout << "Queue Overflow\n";
            return (rear + 1) % size == front;
        }
        // insert
        else
        {
            rear = (rear+1)%size;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue. \n";
        }
    }

    // Pop element, Pop always start from starting.
    void pop()
    {
        // Empty
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }
        else
        {
            if (front == rear) // means queue contains only one element.
            {
                cout << "Popped " << x << " into the Queue\n";
                front = rear = -1; // so bring the front and rear at -1.
            }
            else
            {
                cout << "Popped " << arr[front] << " into the Queue.\n";
                front = (front + 1)%size;
            }
        }
    }

    // needs to return the which element is present at the start.
    int returnStartElement(){
        if (isEmpty())
        {
            cout << "Queue is Empty \n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};


int main()
{
    Queue q(5);
    q.push(5);
    q.push(4);
    q.push(6);
    q.pop();
    q.pop();
    q.pop();
    int x = q.start();
    if(!q.isEmpty()){
        cout << x << " ";
    }
}
