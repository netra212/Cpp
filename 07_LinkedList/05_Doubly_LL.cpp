#include <iostream>
using namespace std;

/**
 * structure of doubly LinkedList.
 * [previousNodeAddress | Data | nextNodeAddress]
 */

class DoubleLinkedListNode
{
public:
    int data;
    DoubleLinkedListNode *next;
    DoubleLinkedListNode *previous;

    DoubleLinkedListNode(int value)
    {
        data = value;
        next = previous = NULL;
    }
};

// Creates a Double LinkedList Using Recursion.
DoubleLinkedListNode *createDLLUsingRecursion(int arr[], int index, int size, DoubleLinkedListNode *back)
{
    if (index == size)
    {
        return NULL;
    }
    DoubleLinkedListNode *temp = new DoubleLinkedListNode(arr[index]);
    temp->previous = back;
    temp->next = createDLLUsingRecursion(arr, index + 1, size, temp);
    return temp;
}

//
int main()
{
    // Insert at the begining of the doubly LinkedList.
    DoubleLinkedListNode *head = NULL;

    // Insert at begining.

    // Two cases.
    // LinkedList does not exist.
    if (head == NULL)
    {
        head = new DoubleLinkedListNode(5);
    }
    // Already exist.
    else
    {
        DoubleLinkedListNode *temp = new DoubleLinkedListNode(5);
        temp->next = head;
        head->previous = temp;
        head = temp;
    }

    DoubleLinkedListNode *traverse = head;
    while (traverse)
    {
        cout << traverse->data << endl;
        traverse = traverse->next;
    }

    // Convert a array into Doubly LinkedList.
    int arr[] = {1, 2, 3, 4, 5};
    DoubleLinkedListNode *tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        // LinkedList does not exist.
        if (head == NULL)
        {
            head = new DoubleLinkedListNode(arr[i]);
            tail = head;
        }
        // LinkedList exist.
        else
        {
            DoubleLinkedListNode *temp = new DoubleLinkedListNode(arr[i]);
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
    }
}
