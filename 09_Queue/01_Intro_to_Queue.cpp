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

// Implementing Queue via LinkedList. 
class Node{
    
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue1{
    Node *front;
    Node *rear;
    public:

    Queue1(){
        front = rear = NULL;
    }
    bool isEmpty(){
        return front == NULL;
    }
    void push(int x){
        if(isEmpty()){
            front == new Node(x);
            rear = front;
            return;
        }else{
            rear->next = new Node(x);
            rear  = rear + 1;
        }
    }
    void pop(){
        if(isEmpty()){
            cout << "Queue underflow\n";
            return;
        }else{
            Node *temp = front;
            front  = front -> next;
            delete temp;
        }
    }
    int start(){ // start returns the front's data. 
        if(isEmpty()){
            cout << "Queue underflow or empty";
            return -1;
        }else{
            return front->data;
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
