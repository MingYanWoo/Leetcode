# 49. 字母异位词分组
# 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

# 示例:

# 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
# 输出:
# [
#   ["ate","eat","tea"],
#   ["nat","tan"],
#   ["bat"]
# ]
# 说明：

# 所有输入均为小写字母。
# 不考虑答案输出的顺序。


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        record = {}
        for s in strs:
            count = [0 for _ in range(26)]
            for c in s:
                index = ord(c)-ord('a')
                count[index] += 1
            count = tuple(count)
            if count not in record:
                record[count] = []
            record[count].append(s)
        
        result = []
        for k,v in record.items():
            result.append(v)
        return result