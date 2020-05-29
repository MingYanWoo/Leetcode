// 103. 二叉树的锯齿形层次遍历
// 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回锯齿形层次遍历如下：

// [
//   [3],
//   [20,9],
//   [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        q.push(pair<TreeNode*,int>(root, 0));
        int curLevel = 0;
        vector<int> tempList;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            auto node = temp.first;
            int level = temp.second;

            if(level > curLevel) {
                res.push_back(tempList);
                tempList.clear();
                curLevel = level;
            }

            tempList.push_back(node->val);

            if(node->left)
                q.push(pair<TreeNode*,int>(node->left, level + 1));
            if(node->right)
                q.push(pair<TreeNode*,int>(node->right, level + 1));
        }

        res.push_back(tempList);

        for(int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};