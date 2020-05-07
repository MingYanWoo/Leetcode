# 39. 组合总和
# 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

# candidates 中的数字可以无限制重复被选取。

# 说明：

# 所有数字（包括 target）都是正整数。
# 解集不能包含重复的组合。 
# 示例 1:

# 输入: candidates = [2,3,6,7], target = 7,
# 所求解集为:
# [
#   [7],
#   [2,2,3]
# ]
# 示例 2:

# 输入: candidates = [2,3,5], target = 8,
# 所求解集为:
# [
#   [2,2,2,2],
#   [2,3,3],
#   [3,5]
# ]


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        candidates.sort()
        def dfs(temp, cur):
            nonlocal target
            if cur > target:
                return
            if cur == target:
                result.append(temp)
                return
            for num in candidates:
                if temp and num < temp[-1]: # 防止重复，小于已添加过的元素直接跳过
                    continue
                dfs(list(temp+[num]), cur+num)
        dfs([], 0)
        return result