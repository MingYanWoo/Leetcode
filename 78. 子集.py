# 78. 子集
# 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

# 说明：解集不能包含重复的子集。

# 示例:

# 输入: nums = [1,2,3]
# 输出:
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]


class Solution:
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        def dfs(subset, nums, k):
            if k == len(nums):
                result.append(subset)
                return
            dfs(subset+[nums[k]], nums, k+1)
            dfs(subset, nums, k+1)
        dfs(list([]), nums, 0)
        return result        