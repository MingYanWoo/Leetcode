// 590. N叉树的后序遍历

// 给定一个 N 叉树，返回其节点值的后序遍历。

// 例如，给定一个 3叉树 : 

// 返回其后序遍历: [5,6,3,2,4,1].

 

// 说明: 递归法很简单，你可以使用迭代法完成此题吗?



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<Node*> children = root->children;
        for(int i = 0; i < children.size(); i++) {
            postorder(children[i]);
        }
        res.push_back(root->val);
        return res;
    }
};