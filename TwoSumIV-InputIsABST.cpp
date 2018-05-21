// 653. Two Sum IV - Input is a BST
// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True
// Example 2:
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False

#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        unordered_set<int> s;
        return helper(root, k, s);
    }
    bool helper(TreeNode *node, int k, unordered_set<int> &s) {
        if (node == NULL) return false;
        if (s.count(k - node->val)) {
            return true;
        }
        s.insert(node->val);
        return helper(node->left, k, s) || helper(node->right, k, s);
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}