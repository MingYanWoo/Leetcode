# 面试题 04.03. 特定深度节点链表
# 给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

 

# 示例：

# 输入：[1,2,3,4,5,null,7,8]

#         1
#        /  \ 
#       2    3
#      / \    \ 
#     4   5    7
#    /
#   8

# 输出：[[1],[2,3],[4,5,7],[8]]


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    
    def listOfDepth(self, tree: TreeNode) -> List[ListNode]:
        if tree == None:
            return []
        queue = [(tree, 1)]
        node_list = []
        result = []
        # bfs
        while queue:
            root, depth = queue.pop(0)
            if depth > len(node_list):
                node_list.append([root])
            else:
                node_list[depth-1].append(root)
            if root.left:
                queue.append((root.left, depth+1))
            if root.right:
                queue.append((root.right, depth+1))
        
        for depth in node_list:
            head = ListNode(depth[0].val)
            pointer = head
            for i in range(1, len(depth)):
                next_node = ListNode(depth[i].val)
                pointer.next = next_node
                pointer = next_node
            result.append(head)

        return result