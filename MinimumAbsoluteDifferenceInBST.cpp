// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
// Note: There are at least two nodes in this BST.

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        InOrder(root, res);
        int min = INT_MAX;
        for (int i = 1; i < res.size(); i++) {
            int diff = res[i] - res[i-1];
            min = diff < min ? diff : min;
        }
        return min;
    }
    
private:
    void InOrder(TreeNode *root, vector<int> &res) {
        if (root != NULL) {
            InOrder(root->left, res);
            res.push_back(root->val);
            InOrder(root->right, res);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}