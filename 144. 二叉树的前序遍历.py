# 144. 二叉树的前序遍历

# 给定一个二叉树，返回它的 前序 遍历。

#  示例:

# 输入: [1,null,2,3]  
#    1
#     \
#      2
#     /
#    3 

# 输出: [1,2,3]
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stack = []
        p = root
        while stack or p:
            while p:
                stack.append(p)
                res.append(p.val)
                p = p.left
            p = stack.pop(-1)
            p = p.right
        return res