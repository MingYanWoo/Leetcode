# 114. 二叉树展开为链表
# 给定一个二叉树，原地将它展开为链表。

# 例如，给定二叉树

#     1
#    / \
#   2   5
#  / \   \
# 3   4   6
# 将其展开为：

# 1
#  \
#   2
#    \
#     3
#      \
#       4
#        \
#         5
#          \
#           6


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        p1, p2 = None, None
        #postorder
        def postorder(root):
            nonlocal p1, p2
            if root == None:
                return
            postorder(root.right)
            postorder(root.left)
            p2 = p1
            p1 = root
            root.right = p2
            root.left = None
        postorder(root)