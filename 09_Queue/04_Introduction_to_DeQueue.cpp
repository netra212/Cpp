#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <dequeue>
using namespace std;

/**
    Dequeue -> Double Ended queue. 
*/

// Implementing LinkedList using Dequeue. 
class Node{
    public:
    int data;
    Node *next, *prev;

    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

class Dequeue{
    Node *front, rear;
    public:
    Dequeue(){
        front = rear = NULL;
    }
    // push front
    void pushFront(int x){
        if(front == NULL){
            front = rear = Node(x);
            cout << "Pushed " << x << " in front of Dequeue";
        }else{
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "Pushed " << x << " in front of Dequeue";
            return;
        }
    }
    // push back
    void pushBack(int x){
        if(front == NULL){
            front = rear = Node(x);
            cout << "Pushed " << x << " in 
            back of Dequeue";
        }else{
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "Pushed " << x << " in back of Dequeue";
            return;
        }
    }
    // pop front
    void popFront(){
        if(front == NULL){
            cout << "Dequeue underflow\n" << endl;
            return;
        }else{
            Node *temp = front;
            cout << "Popped " << temp->data << " from front."
            front = front->next;
            delete temp;

            // cases. 
            // 1 node. 
            // Greater than 1 node. 
            if(front){
                front->prev = NULL;
            }else{
                rear = NULL;
            }
        }
    }
    // pop back
    void popFront(){
        if(front == NULL){
            cout << "Dequeue underflow\n" << endl;
            return;
        }else{
            Node *temp = rear;
            cout << "Popped " << temp->data << " from front."
            rear = rear->prev;
            delete temp;

            // cases. 
            // 1 node. 
            // Greater than 1 node. 
            if(front){
                rear->next = NULL;
            }else{
                front = NULL;
            }
        }
    }
    // start
    int start(){
        if(front == NULL){
            return -1;
        }else{
            return front->data;
        }
    }
    // end
    int end(){
        if(front == NULL){
            return -1;
        }else{
            return rear->data;
        }
    }
};


// Implementing Deque using Array
class DeqeueViaArray{
    int front, rear, size;
    int *arr;
    public:
    Deque(int n){
        size = n;
        arr = new int[n];
        front = rear - 1;
    }

    void isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void push_front(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            return;
        }else if(isFull()){
            return;
        }else{
            front = (front - 1 + size)%size;
            arr[front] = x;
        }
    }

    void push_back(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
        }else if(isFull()){
            return;
        }else{
            rear = (rear + 1) % size;
            arr[rear] = x;
            return;
        }
    }

    void pop_front(){
        if(isEmpty()){
            return;
        }else{
            if(front == rear){
                front = rear = -1;
            }else{
                front = (front + 1) % size;
            }
        }
    }

    void pop_front(){
        if(isEmpty()){
            return;
        }
        else{
             if(front == rear){
                front = rear = -1;
            }else{
                rear = (rear  1 + size) % size;
            }
        }
    }
}


int main(){
    dequeue<int> d;
    d.push_back(5);
    d.pop_back(3);
}


