// 剑指 Offer 33. 二叉搜索树的后序遍历序列

// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

 

// 参考以下这颗二叉搜索树：

//      5
//     / \
//    2   6
//   / \
//  1   3
// 示例 1：

// 输入: [1,6,3,2,5]
// 输出: false
// 示例 2：

// 输入: [1,3,2,6,5]
// 输出: true
 

// 提示：

// 数组长度 <= 1000




class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        return helper(postorder, 0, postorder.size()-1);
    }
    bool helper(vector<int>& postorder, int l, int r) {
        if(l >= r) return true;
        int root = postorder[r];
        int pos = l;
        for(; pos <= r - 1; pos++) {
            if(postorder[pos] > root) break;
        }
        for(int i = pos; i <= r - 1; i++) {
            if(postorder[i] < root) return false;
        }
        return helper(postorder, l, pos-1) && helper(postorder, pos, r-1);
    }
};