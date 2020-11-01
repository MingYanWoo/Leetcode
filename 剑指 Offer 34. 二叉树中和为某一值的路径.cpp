// 剑指 Offer 34. 二叉树中和为某一值的路径

// 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

 

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// 返回:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
 

// 提示：

// 节点总数 <= 10000
// 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/




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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, res, path);
        return res;
    }

    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> path) {
        if(!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && !root->left && !root->right) {
            res.push_back(path);
            return;
        }
        dfs(root->left, sum, res, path);
        dfs(root->right, sum, res, path);
    }
};