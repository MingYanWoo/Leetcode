# 面试题 04.12. 求和路径
# 给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。注意，路径不一定非得从二叉树的根节点或叶节点开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。

# 示例:
# 给定如下二叉树，以及目标和 sum = 22，

#               5
#              / \
#             4   8
#            /   / \
#           11  13  4
#          /  \    / \
#         7    2  5   1
# 返回:

# 3
# 解释：和为 22 的路径有：[5,4,11,2], [5,8,4,5], [4,11,7]
# 提示：

# 节点总数 <= 10000
# 通过次数2,065提交次数4,370

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    result = 0
    def pathSum(self, root: TreeNode, sum: int) -> int:
        depth = self.depth(root)
        paths = [0 for _ in range(depth)]
        self.count(root, sum, 0, list(paths))
        return self.result

    
    def count(self, root, sum, depth, paths):
        if root == None:
            return
        paths[depth] = root.val
        temp = 0
        for i in range(depth, -1, -1):
            temp += paths[i]
            if temp == sum:
                self.result += 1
        self.count(root.left, sum, depth+1, list(paths))
        self.count(root.right, sum, depth+1, list(paths))

    
    def depth(self, root):
        if root == None:
            return 0
        return max(self.depth(root.left) + 1, self.depth(root.right) + 1)