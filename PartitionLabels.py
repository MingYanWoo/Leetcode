# 763. Partition Labels

# A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

# Example 1:

# Input: S = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
# Note:

# S will have length in range [1, 500].
# S will consist of lowercase letters ('a' to 'z') only.

class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        
        last_dict = {}
        result = []
        for i in range(len(S)):
            if not last_dict.has_key(S[i]):
                last_dict[S[i]] = i
            last_dict[S[i]] = i
        
        start, last = 0, 0
        for i in range(len(S)):
            last = max(last, last_dict[S[i]])
            if i == last:
                length = last - start + 1
                start = i + 1
                result.append(length)
                
        return result