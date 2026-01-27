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

//
int main()
{
}
