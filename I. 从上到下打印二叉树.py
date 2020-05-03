# 面试题32 - I. 从上到下打印二叉树
# 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

# 例如:
# 给定二叉树: [3,9,20,null,null,15,7],

#     3
#    / \
#   9  20
#     /  \
#    15   7
# 返回：

# [3,9,20,15,7]
 

# 提示：

# 节点总数 <= 1000


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        result = []
        if root == None:
            return result
        queue = [root]
        while queue:
            node = queue.pop(0)
            result.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return result