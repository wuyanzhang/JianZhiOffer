class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def ReverseList(self,head):
        newHead = None
        while head:
            t = head.next
            head.next = newHead
            newHead = head
            head = t
        return newHead

if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l4 = ListNode(4)
    l1.next = l2
    l2.next = l3
    l3.next = l4
    s = Solution()
    head = s.ReverseList(l1)
    while head:
        print(head.val,end=' ')
        head = head.next