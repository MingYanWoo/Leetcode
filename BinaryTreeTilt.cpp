// 563. Binary Tree Tilt

// Given a binary tree, return the tilt of the whole tree.

// The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.

// The tilt of the whole tree is defined as the sum of all nodes' tilt.

// Example:

// Input: 
//          1
//        /   \
//       2     3
// Output: 1
// Explanation: 
// Tilt of node 2 : 0
// Tilt of node 3 : 0
// Tilt of node 1 : |2-3| = 1
// Tilt of binary tree : 0 + 0 + 1 = 1
// Note:

// The sum of node values in any subtree won't exceed the range of 32-bit integer.
// All the tilt values won't exceed the range of 32-bit integer.

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
    int findTilt(TreeNode* root) {
        int result = 0;
        postorder(root, result);
        return result;
    }
    
    int postorder(TreeNode* node, int &res) {
        if (node == NULL) {
            return 0;
        }
        int leftsum = postorder(node->left, res);
        int rightsum = postorder(node->right, res);
        res += abs(leftsum - rightsum);
        return leftsum + rightsum + node->val;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}