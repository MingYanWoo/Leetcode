# 102. 二叉树的层序遍历
# 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

# 示例：
# 二叉树：[3,9,20,null,null,15,7],

#     3
#    / \
#   9  20
#     /  \
#    15   7
# 返回其层次遍历结果：

# [
#   [3],
#   [9,20],
#   [15,7]
# ]


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        queue = [(root, 1)]
        result = []
        while queue:    #bfs
            root, depth = queue.pop(0)
            if depth > len(result):
                result.append([])
            result[depth-1].append(root.val)
            if root.left:
                queue.append((root.left, depth+1))
            if root.right:
                queue.append((root.right, depth+1))
        return result
