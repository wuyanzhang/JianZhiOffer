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

int FindKthToTail(ListNode* head, int k)
{
    if(head == NULL || head->next == NULL)
        return -1;
    ListNode *p = head->next;
    ListNode *q = head;
    for(int i = 0; i < k; i++)
    {
        q = q->next;
    }
    while(q->next)
    {
        p = p->next;
        q = q->next;
    }
    return p->val;
}

int main()
{
    int len,k;
    cin >> len >> k;
    int result = FindKthToTail(CreateList(len),k);
    cout << result;
    return 0;
}