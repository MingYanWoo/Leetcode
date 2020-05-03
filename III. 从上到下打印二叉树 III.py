面试题32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
 

提示：

节点总数 <= 1000


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root == None:
            return result
        queue = [(root, 1)]
        odd_list = []
        even_list = []
        while queue:
            node, depth = queue.pop(0)
            if node.left:
                queue.append((node.left, depth+1))
            if node.right:
                queue.append((node.right, depth+1))

            if depth % 2 == 1:
                if even_list:
                    even_list.reverse()
                    result.append(even_list)
                    even_list = []
                odd_list.append(node.val)
            else:
                if odd_list:
                    result.append(odd_list)
                    odd_list = []
                even_list.append(node.val)
        if even_list:
            even_list.reverse()
            result.append(even_list)
        else:
            result.append(odd_list)
        return result