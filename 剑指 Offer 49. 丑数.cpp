// 剑指 Offer 49. 丑数

// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

// 示例:

// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
// 说明:  

// 1 是丑数。
// n 不超过1690。
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/



class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            int av = dp[a] * 2, bv = dp[b] * 3, cv = dp[c] * 5;
            dp[i] = min(av, min(bv, cv));
            if(dp[i] == av) a++;
            if(dp[i] == bv) b++;
            if(dp[i] == cv) c++;
        }
        return dp[n-1];
    }
};