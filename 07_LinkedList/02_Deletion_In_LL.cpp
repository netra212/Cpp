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

// Deleting a particular node.
Node *deleteParticularNode(Node *head, int x)
{
    if (x == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    x--;

    Node *curr = head;
    Node *prev = NULL;

    while (x--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return head;
}

//  Deleting a Particular Node Using recursion.
Node *deleteAParticularNodeWithRecursion()
{
    //
}

// Delete without having a head pointer.
void deleteWithoutHeadNode(Node *curr)
{
    Node *temp = curr->next;
    curr->data = temp->data;
    curr->next = temp->next;
    delete temp;
}

//
int main()
{
    Node *head;
    head = NULL;

    int arr[] = {2, 4, 5, 1, 7};

    // 1. Delete a Node at start.
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // 2. Delete a Last Node.
    // If Node exist.
    if (head != NULL)
    {
        // Only one node is present.
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // more than 1 node is present.
        else
        {
            Node *current = head;
            Node *previous = NULL;

            // current->next is not NULL.
            while (current->next != NULL)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
        }
    }

    // 3. Delete a Particular Node.
}
