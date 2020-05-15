// 494. 目标和
// 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

// 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

// 示例 1:

// 输入: nums: [1, 1, 1, 1, 1], S: 3
// 输出: 5
// 解释: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// 一共有5种方法让最终目标和为3。
// 注意:

// 数组非空，且长度不会超过20。
// 初始的数组的和不会超过1000。
// 保证返回的最终结果能被32位整数存下。


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        dfs(nums, S, 0, result, 0);
        return result;
    }

    void dfs(vector<int>& nums, int S, int tempSum, int& res, int pointer) {
        if(pointer == nums.size()) {
            if(tempSum == S) {
                res++;
            }
            return;
        }
        dfs(nums, S, tempSum+nums[pointer], res, pointer+1);
        dfs(nums, S, tempSum-nums[pointer], res, pointer+1);
    }
};