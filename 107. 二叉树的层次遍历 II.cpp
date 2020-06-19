// 107. 二叉树的层次遍历 II
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其自底向上的层次遍历为：

// [
//   [15,7],
//   [9,20],
//   [3]
// ]



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> p(root, 0);
        q.push(p);
        int curLevel = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            auto root  = p.first;
            int level = p.second;
            if(level > curLevel) {
                ans.push_back(temp);
                temp.clear();
                curLevel = level;
            }
            temp.push_back(root->val);
            if(root->left) q.push(pair<TreeNode*, int>(root->left, level+1));
            if(root->right) q.push(pair<TreeNode*, int>(root->right, level+1));
        }
        ans.push_back(temp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};