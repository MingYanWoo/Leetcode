// 面试题 16.17. 连续数列

// 给定一个整数数组，找出总和最大的连续数列，并返回总和。

// 示例：

// 输入： [-2,1,-3,4,-1,2,1,-5,4]
// 输出： 6
// 解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶：

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxV = INT_MIN;
        int cur = 0;
        for(auto v : nums) {
            if(cur < 0) {
                cur = v;
            }else {
                cur += v;
            }
            maxV = max(maxV, cur);
        }
        return maxV;
    }
};