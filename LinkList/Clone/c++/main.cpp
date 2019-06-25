#include <iostream>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next,*random;
};

RandomListNode* CreateList(int n)
{
    RandomListNode *p,*s;
    RandomListNode *head;
    head = (RandomListNode*)malloc(sizeof(RandomListNode));
    head->next = NULL;
    p = head;
    for(int i = 0; i < n; i++)
    {
        s = (RandomListNode*)malloc(sizeof(RandomListNode));
        cin >> s->label;
        s->next = NULL;
        p->next = s;
        p = p->next;
    }
    return head;
}

RandomListNode *CreateRandomList(RandomListNode *head)
{
    RandomListNode *p = head->next;
    p->random = p->next->next;
    p->next->random = p->next->next->next->next;
    p->next->next->next->random = p->next;
    return head;
}

void CloneNodes(RandomListNode *head)
{
    RandomListNode *p = head->next;
    while(p)
    {
        RandomListNode *clone = (RandomListNode*)malloc(sizeof(RandomListNode));
        clone->label = p->label;
        clone->next = p->next;
        p->next = clone;
        clone->random = NULL;
        p = clone->newccxt;
    }
}

void ConnectSiblingNodes(RandomListNode *head)
{
    RandomListNode *p = head->next;
    while(p)
    {
        RandomListNode *clone = p->next;
        if(p->random != NULL)
        {
            clone->random = p->random->next;
        }
        p = clone->next;
    }
}

RandomListNode *ReconnectNodes(RandomListNode *head)
{
    RandomListNode *p = head->next;
    RandomListNode *cloneHead = NULL;
    RandomListNode *cloneNode = NULL;
    if(p != NULL)
    {
        cloneHead = cloneNode = p->next;
        p->next = cloneNode->next;
        p = p->next;
    }
    while(p != NULL)
    {
        cloneNode->next = p->next;
        cloneNode = cloneNode->next;
        p->next = cloneNode->next;
        p = p->next;
    }
    return cloneHead;
}

RandomListNode *Clone(RandomListNode *head)
{
    CloneNodes(head);
    ConnectSiblingNodes(head);
    return ReconnectNodes(head);
}

int main()
{
    int n;
    cin >> n;
    RandomListNode *head = CreateRandomList(CreateList(n));
    head = Clone(head);
    while(head)
    {
        if(head->random != NULL)
        {
            cout << head->label << ", " << head->random->label << endl;
            head = head->next;
        }
        else
        {
            cout << head->label << endl;
            head = head->next;
        }
    }
    return 0;
}