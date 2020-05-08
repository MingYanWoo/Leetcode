# 148. 排序链表

# 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

# 示例 1:

# 输入: 4->2->1->3
# 输出: 1->2->3->4
# 示例 2:

# 输入: -1->5->3->4->0
# 输出: -1->0->3->4->5


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        quickP = head.next
        slowP = head
        while quickP and quickP.next:
            quickP = quickP.next.next
            slowP = slowP.next
        
        mid = slowP.next
        slowP.next = None
        left = self.sortList(head)
        right = self.sortList(mid)

        res = ListNode(0)
        temp = res
        while left and right:
            if left.val < right.val:
                temp.next = left
                left = left.next
            else:
                temp.next = right
                right = right.next
            temp = temp.next
        
        temp.next = left if left else right
        return res.next
