#include <iostream>
using namespace std;

class ListNode
{
public:
    int value;
    ListNode *next;

    ListNode(int data)
    {
        value = data;
        next = NULL;
    }
};

//
ListNode *reverseLinkedList(ListNode *head)
{
    /**
     *[1 | 200] -> [2 | 400] -> [3 | 300] -> [4 | 800] -> [5 | NULL]
     */
    vector<int> ans;
    ListNode *temp = head;
    while (temp != NULL)
    {
        ans.push_back(temp->value);
        temp = temp->next;
    }

    int i = ans.size() - 1;
    temp = head;
    while (temp != NULL)
    {
        temp->value = ans[i];
        i--;
        temp = temp->next;
    }
    return head;
}

// Reverse a Node.
ListNode *reverseLinkedNode(ListNode *head)
{
    ListNode *curr = head, *prev = NULL, *future = NULL;
    while (curr)
    {
        future = curr->next;
        curr->next = prev;
        prev = future;
    }

    head = prev;
    return head;
}

// Reverse a LinkedList Using Recursion.
ListNode *reverseLinkedListUsingRecursion(ListNode *curr, ListNode *prev)
{
    if (curr == NULL)
    {
        return prev;
    }
    ListNode *fut = curr->next;
    curr->next = prev;
    return reverseLinkedListUsingRecursion(fut, curr);
}

// Middle of LinkedList.
ListNode *middleOfLinkedList(ListNode *head)
{
    int count = 0; // Count total number of nodes.
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    count /= 2;
    temp = head;
    while (count--)
    {
        temp = temp->next;
    }
    return temp;
}

//
int main()
{
    //
}
