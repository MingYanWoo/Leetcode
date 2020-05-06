# 101. 对称二叉树
# 给定一个二叉树，检查它是否是镜像对称的。

 

# 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

#     1
#    / \
#   2   2
#  / \ / \
# 3  4 4  3
 

# 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

#     1
#    / \
#   2   2
#    \   \
#    3    3
 

# 进阶：

# 你可以运用递归和迭代两种方法解决这个问题吗？


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.isSame(root.left, root.right)
        

    def isSame(self, p1, p2):
        if not p1 and not p2:
            return True
        if p1 and p2:
            if p1.val == p2.val:
                return self.isSame(p1.left, p2.right) and self.isSame(p1.right, p2.left)
        return False