// 322. 零钱兑换
// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 

// 示例 1:

// 输入: coins = [1, 2, 5], amount = 11
// 输出: 3 
// 解释: 11 = 5 + 5 + 1
// 示例 2:

// 输入: coins = [2], amount = 3
// 输出: -1
 

// 说明:
// 你可以认为每种硬币的数量是无限的。


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i = 0; i < amount+1; i++) {
            dp[i] = amount+1;
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(auto c : coins) {
                if(i - c >= 0) {
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};