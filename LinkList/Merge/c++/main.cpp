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


ListNode *Merge(ListNode *p,ListNode *q)
{
    ListNode *head = NULL;
    if(p == NULL)
        return q;
    else if(q == NULL)
        return p;
    if(p->val < q->val)
    {
        head = p;
        head->next = Merge(p->next,q);
    }
    else
    {
        head = q;
        head->next = Merge(p,q->next);
    }
    return head;
}

int main()
{
    int n,m;
    cin >> n >> m;
    ListNode *p = CreateList(n);
    p = p->next;
    ListNode *q = CreateList(m);
    q = q->next;
    ListNode *head = Merge(p,q);
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}