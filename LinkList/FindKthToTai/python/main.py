class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self,head,k):
        if head == None or k == 0:
            return None
        p = head
        q = head
        for i in range(k-1):
            if p.next == None:
                return None
            else:
                p = p.next
        while p.next != None:
            p = p.next
            q = q.next
        return q.val

    # 用列表
    def FindKthToTail2(self,head,k):
        l = []
        while head:
            l.append(head.val)
            head = head.next
        if len(l) < k or k < 1:
            return None
        return l[-k]

if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l4 = ListNode(4)
    l1.next = l2
    l2.next = l3
    l3.next = l4
    s = Solution()
    result = s.FindKthToTail2(l1,2)
    print(result)
