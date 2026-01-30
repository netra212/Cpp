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

// Insert at any points.
void InsertNodeAtAnyGivenPosition(int pos)
{
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

    // Create Doubly LinkedList using Recursion.

    // Insert at any given position.
    int pos = 2;
    // insert at start.
    if (pos == 0)
    {
        // case1: LinkedList does not exit.
        if (head == NULL)
        {
            head = new DoubleLinkedListNode(5);
        }
        // case2: LinkedList exist.
        else
        {
            DoubleLinkedListNode *temp = new DoubleLinkedListNode(5);
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
    }
    else
    {
        DoubleLinkedListNode *curr = head;
        // Go to the node, after which i have to insert.
        while (--pos)
        {
            curr = curr->next;
        };
        // insert at end.
        if (curr->next == NULL) // Last node
        {
            DoubleLinkedListNode *temp = new DoubleLinkedListNode(5);
            temp->previous = curr;
            curr->next = temp;
        }
        else // Insert at Middle.
        {
            DoubleLinkedListNode *temp = new DoubleLinkedListNode(5);
            temp->next = curr->next;
            temp->previous = curr;
            curr->next = temp;
            temp->next->previous = temp;
        }
    }
    // Delete at start.
    if (head != NULL)
    {
        // If only one Node exist.
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If more than 1 Node exist.
        else
        {
            DoubleLinkedListNode *temp = head;
            head = head->next;
            delete temp;
            head->previous = NULL;
        }
    }
    // Delete at end.
    if (head != NULL)
    {
        // If only 1 Node exist.
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If more than 1 Node exist.
        else
        {
            DoubleLinkedListNode *curr = head;
            // current node laii last samma line.
            while (curr->next)
            {
                curr = curr->next;
            }

            curr->previous->next = NULL;
            delete curr;
        }
    }
    // Delete at any given position.
    int pos = 3;
    // delete at start;
    if (pos == 1)
    {
        // If only one Node exist.
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If more than 1 Node exist.
        else
        {
            DoubleLinkedListNode *temp = head;
            head = head->next;
            delete temp;
            head->previous = NULL;
        }
    }
    else
    {
        DoubleLinkedListNode *curr = head;
        while (--pos)
        {
            curr = curr->next;
        }
        // delete at end;
        if (curr->next == NULL)
        {
            //
            curr->previous->next = NULL;
            delete curr;
        }
        else
        {
            // delete at middle;
            curr->previous->next = curr->next;
            curr->next->previous = curr->previous;
            delete curr;
        }
    }
}
