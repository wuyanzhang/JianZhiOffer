class RandomListNode:
    def __init__(self,x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    def CloneNodes(self,head):
        p = head
        while p:
            clone = RandomListNode(-1)
            clone.label = p.label
            clone.next = p.next
            p.next = clone
            clone.random = None
            p = clone.next

    def ConnectSiblingNodes(self,head):
        p = head
        while p:
            clone = p.next
            if p.random:
                clone.random = p.random.next
            p = clone.next

    def ReconnectNodes(self,head):
        p = head
        cloneHead = None
        cloneNode = None
        if p:
            cloneHead = cloneNode = p.next
            p.next = cloneNode.next
            p = p.next
        while p:
            cloneNode.next = p.next
            cloneNode = cloneNode.next
            p.next = cloneNode.next
            p = p.next
        return cloneHead

    def Clone(self,head):
        self.CloneNodes(head)
        self.ConnectSiblingNodes(head)
        return self.ReconnectNodes(head)

if __name__ == '__main__':
    l1 = RandomListNode(1)
    l2 = RandomListNode(2)
    l3 = RandomListNode(3)
    l4 = RandomListNode(4)
    l5 = RandomListNode(5)
    l1.next = l2
    l2.next = l3
    l3.next = l4
    l4.next = l5
    l1.random = l3
    l2.random = l5
    l4.random = l2

    s = Solution()
    head = s.Clone(l1)

    while head:
        if head.random:
            print(head.label,end=', ')
            print(head.random.label)
            head = head.next
        else:
            print(head.label)
            head = head.next