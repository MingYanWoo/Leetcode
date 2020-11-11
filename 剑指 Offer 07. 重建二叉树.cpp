// 剑指 Offer 07. 重建二叉树

// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7
 

// 限制：

// 0 <= 节点个数 <= 5000




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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        int l = 0, r = preorder.size() - 1;
        return buildTree(preorder, inorder, l, r, l, r);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl > pr || il > ir) return NULL;
        TreeNode *root = new TreeNode(preorder[pl]);
        int rootIdx = il;
        for(int i = il; i <= ir; i++) {
            if(inorder[i] == preorder[pl]) {
                rootIdx = i;
                break;
            }
        }
        int leftNum = rootIdx - il;
        root->left = buildTree(preorder, inorder, pl+1, pl+leftNum, il, rootIdx-1);
        root->right = buildTree(preorder, inorder, pl+leftNum+1, pr, rootIdx+1, ir);
        return root;
    }
};