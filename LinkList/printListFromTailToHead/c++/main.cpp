#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
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

vector<int> printListFromTailToHead(ListNode *head)
{
    stack<int> stk;
    vector<int> result;
    ListNode *p = head->next;
    while(p != NULL)
    {
        stk.push(p->val);
        p = p->next;
    }
    while(!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    ListNode *head = CreateList(n);
    vector<int> result = printListFromTailToHead(head);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}