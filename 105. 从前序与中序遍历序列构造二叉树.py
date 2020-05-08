# 105. 从前序与中序遍历序列构造二叉树

# 根据一棵树的前序遍历与中序遍历构造二叉树。

# 注意:
# 你可以假设树中没有重复的元素。

# 例如，给出

# 前序遍历 preorder = [3,9,20,15,7]
# 中序遍历 inorder = [9,3,15,20,7]
# 返回如下的二叉树：

#     3
#    / \
#   9  20
#     /  \
#    15   7


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        rootVal = preorder[0]
        rootIndex = -1
        for i in range(len(inorder)):
            if inorder[i] == rootVal:
                rootIndex = i
                break
        left_preorder = preorder[1:1+i]
        left_inorder = inorder[:i]
        right_preorder = preorder[1+i:]
        right_inorder = inorder[i+1:]

        root = TreeNode(rootVal)
        root.left = self.buildTree(left_preorder, left_inorder)
        root.right = self.buildTree(right_preorder, right_inorder)
        return root