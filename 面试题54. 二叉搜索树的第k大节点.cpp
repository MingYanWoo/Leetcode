// 面试题54. 二叉搜索树的第k大节点
// 给定一棵二叉搜索树，请找出其中第k大的节点。

 

// 示例 1:

// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4
// 示例 2:

// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 4
 

// 限制：

// 1 ≤ k ≤ 二叉搜索树元素个数



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int count = 0, ans = -1;
        inorder(root, k, count, ans);
        return ans;
    }

    void inorder(TreeNode* root, int& k, int& count, int& ans) {
        if(!root) return;
        inorder(root->right, k, count, ans);
        count++;
        if(count == k) {
            ans = root->val;
            return;
        }
        inorder(root->left, k, count, ans);
    }
};