# 46. 全排列
# 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

# 示例:

# 输入: [1,2,3]
# 输出:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        def dfs(nums, subset):
            if not nums:
                result.append(subset)
                return
            for i in range(len(nums)):
                subset.append(nums[i])
                dfs(list(nums[:i]+nums[i+1:]), list(subset))    # 删除自己，传到下一层
                subset.pop()
        dfs(nums, list([]))
        return result