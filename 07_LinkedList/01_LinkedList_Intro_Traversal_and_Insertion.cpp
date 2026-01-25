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

int main()
{
    Node *head;
    head = new Node(4);

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
        cout << temp->data << endl;
        temp = temp->next;
    };

    // Inserting at the last of the LinkedList.
}

//