class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def Merge(self,p,q):
        if not p:
            return q
        if not q:
            return p
        head = None
        if p.val < q.val:
            head = p
            head.next = self.Merge(p.next,q)
        else:
            head = q
            head.next = self.Merge(p,q.next)
        return head

if __name__ == '__main__':
    l1 = ListNode(1)
    head1 = l1
    for i in range(2,4):
        p = ListNode(i)
        l1.next = p
        l1 = l1.next
    l2 = ListNode(2)
    head2 = l2
    for i in range(3,5):
        p = ListNode(i)
        l2.next = p
        l2 = l2.next
    s = Solution()
    head = s.Merge(head1,head2)
    while head:
        print(head.val, end=' ')
        head = head.next



