// 404.Sum of Left Leaves

// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int result = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return result;
    }
    
    void helper(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            if (root->left->left==NULL && root->left->right==NULL) {
                result += root->left->val;
            }
        }
        helper(root->left);
        helper(root->right);
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}