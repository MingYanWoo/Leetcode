# 560. 和为K的子数组
# 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

# 示例 1 :

# 输入:nums = [1,1,1], k = 2
# 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
# 说明 :

# 数组的长度为 [1, 20,000]。
# 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hashMap = {0:1}
        result = 0
        tempSum = 0
        for num in nums:
            tempSum += num
            if tempSum-k in hashMap:
                result += hashMap[tempSum-k]
            if tempSum not in hashMap:
                hashMap[tempSum] = 0
            hashMap[tempSum] += 1
        return result
