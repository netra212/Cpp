#include <iostream>
using namespace std;

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

// Add the Node at the End using Recursion.
// Creating a LinkedList using recursion by adding node at the end.
Node *addNodeAtEnd(int arr[], int index, int size)
{
    // return type of the function is Node or address type.
    if (index == size)
    {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = addNodeAtEnd(arr, index + 1, size);

    return temp;
}

// Adding the Node at the begining of the LinkedList.
Node *addNodeAtBegining(int arr[], int index, int size, Node *previousAddress)
{
    if (index == size)
    {
        return previousAddress;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = previousAddress;
    return addNodeAtBegining(arr, index + 1, size, temp);
}

//
int main()
{
    Node *head, *tail;
    // head = new Node(4);
    tail = head = NULL;

    // cout << head->data << endl;
    // cout << head->next << endl;

    int arr[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; i++)
    {
        // Inserting the Node at the begining.

        // LinkedList does not exist.
        if (head == NULL)
        {
            head = new Node(arr[i]);
        }
        else
        {
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = head;
            head = temp;
        }
    }

    // Print the values.
    Node *temp = head;
    while (temp != NULL)
    {
        cout << " Printing values: " << endl;
        cout << temp->data << endl;
        temp = temp->next;
    };

    // Inserting at the last of the LinkedList.

    // LinkedList is empty.
    for (int i = 0; i < 5; i++)
    {
        if (head == NULL)
        {
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }

    // Printing the values of the LinkedList.
    Node *temp1;
    temp1 = head;

    while (temp1)
    {
        cout << temp1->data << " " << endl;
        temp1 = temp1->next;
    }

    // Calling the function.
    head = addNodeAtEnd(arr, 0, 5);
    Node *temp2;
    temp2 = head;

    while (temp2)
    {
        cout << temp2->data << " " << endl;
        temp2 = temp2->next;
    }

    //
    head = addNodeAtBegining(arr, 0, 5, head);

    // Inserting a Node at the Middle or Between the LinkedList or particularPosition.
    int x = 3;
    int value = 30;

    Node *temp = head;
    x--;

    while (x--)
    {
        temp = temp->next;
    }
    Node *temp2;
    temp2 = new Node(value);
    temp2->next = temp->next;
    temp->next = temp;
}

//