# 416. 分割等和子集
# 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

# 注意:

# 每个数组中的元素不会超过 100
# 数组的大小不会超过 200
# 示例 1:

# 输入: [1, 5, 11, 5]

# 输出: true

# 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

# 示例 2:

# 输入: [1, 2, 3, 5]

# 输出: false

# 解释: 数组不能分割成两个元素和相等的子集.


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if len(nums) == 0:
            return 0
        total = 0
        for num in nums:
            total += num
            
        if total % 2 == 1:
            return False
        
        dp = [[False for _ in range(total // 2 + 1)] for _ in range(len(nums)+1)]

        for i in range(1,len(nums)+1):
            for j in range(1, total // 2+1):
                dp[i][j] = dp[i-1][j]

                if nums[i-1] == j:
                    dp[i][j] = True
                    continue
                if nums[i-1] < j:
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j]
        return dp[-1][-1]