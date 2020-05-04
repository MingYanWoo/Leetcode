# 437. 路径总和 III
# 给定一个二叉树，它的每个结点都存放着一个整数值。

# 找出路径和等于给定数值的路径总数。

# 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

# 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

# 示例：

# root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

#       10
#      /  \
#     5   -3
#    / \    \
#   3   2   11
#  / \   \
# 3  -2   1

# 返回 3。和等于 8 的路径有:

# 1.  5 -> 3
# 2.  5 -> 2 -> 1
# 3.  -3 -> 11


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    count = 0
    def pathSum(self, root: TreeNode, sum: int) -> int:
        depth = self.depth(root)
        path = [0 for _ in range(depth)]
        self.dfs(root, sum, list(path), 0)
        return self.count

    
    def dfs(self, root, nodeSum, path, depth):
        if root == None:
            return
        path[depth] = root.val
        tempSum = 0
        for i in range(depth, -1, -1):
            tempSum += path[i]
            if tempSum == nodeSum:
                self.count += 1
        self.dfs(root.left, nodeSum, list(path), depth+1)
        self.dfs(root.right, nodeSum, list(path), depth+1)

    def depth(self, root):
        if root == None:
            return 0
        return max(self.depth(root.left)+1, self.depth(root.right)+1)