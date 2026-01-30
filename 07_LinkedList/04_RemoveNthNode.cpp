#include <iostream>
using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;

    ListNode(int data)
    {
        data = value;
        next = NULL;
    }
};

// Q. Remove nth node from the end.and return the head of the first node.
ListNode *removeNthNodeFromEnd(ListNode *head, int n)
{
    int count = 0;
    ListNode *temp = head;

    // Count total number of ListNodes.
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count -= n;
    if (count == 0) // if need to delete the first node.
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return head;
}

// Q. Remove Every Kth Node.
ListNode *removeEveryKthNode()
{
    //
}

//
int main()
{
    //
}