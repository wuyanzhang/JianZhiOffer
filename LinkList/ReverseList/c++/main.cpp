#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* CreateList(int n)
{
    ListNode *p,*s;
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    p = head;
    for(int i = 0; i < n; i++)
    {
        s = (ListNode*)malloc(sizeof(ListNode));
        cin >> s->val;
        s->next = NULL;
        p->next = s;
        p = p->next;
    }
    return head;
}

ListNode* ReverseList(ListNode* head)
{
    ListNode* newHead = NULL;
    head = head->next;
    while(head)
    {
        ListNode* t = head->next;
        head->next = newHead;
        newHead = head;
        head = t;
    }
    ListNode* new_head;
    new_head->next = newHead;
    return new_head;
}

int main()
{
    int n;
    cin >> n;
    ListNode* head = ReverseList(CreateList(n));
    while(head->next != NULL)
    {
        cout << head->next->val << " ";
        head = head->next;
    }
    return 0;
}