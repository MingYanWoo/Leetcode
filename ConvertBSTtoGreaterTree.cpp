// 538. Convert BST to Greater Tree

// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

// Example:

// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13

// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
    void helper(TreeNode*& node, int& sum) {
        if (!node) return;
        helper(node->right, sum);
        node->val += sum;
        sum = node->val;
        helper(node->left, sum);
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}
