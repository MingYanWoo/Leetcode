#include <iostream>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = (int)q.size();
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            double avg = sum / n;
            res.push_back(avg);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}
