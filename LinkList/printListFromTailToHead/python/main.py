class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def printListFromTailToHead(listNode):
        # write code here
        result = []
        while listNode:
            result.insert(0, listNode.val)
            listNode = listNode.next
        return result

if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l4 = ListNode(4)
    l1.next = l2
    l2.next = l3
    l3.next = l4
    result = Solution.printListFromTailToHead(l1)
    print(result)