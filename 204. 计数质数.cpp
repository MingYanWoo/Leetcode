// 204. 计数质数
// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。


class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        for(int i = 2; i < n; i++) {
            if(nums[i]) {
                for(int j = 2 * i; j < n; j += i) {
                    nums[j] = false;
                }
            }
        }
        int result = 0;
        for(int i = 2; i < n; i++) {
            if(nums[i]) result++;
        }
        return result;
    }
};