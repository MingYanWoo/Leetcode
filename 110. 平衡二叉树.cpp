// 110. 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树。

// 本题中，一棵高度平衡二叉树定义为：

// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

 

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：true
// 示例 2：


// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false
// 示例 3：

// 输入：root = []
// 输出：true
 

// 提示：

// 树中的节点数在范围 [0, 5000] 内
// -104 <= Node.val <= 104



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {	// O(n^2)
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 &&
        isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode* root) {
        if(!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};


class Solution {	// O(n)
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }
    
    int depth(TreeNode* root) {
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left == -1 || right == -1|| abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
};