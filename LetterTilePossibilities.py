# 1079. Letter Tile Possibilities

# You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

# Example 1:

# Input: "AAB"
# Output: 8
# Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
# Example 2:

# Input: "AAABBC"
# Output: 188
 

# Note:

# 1 <= tiles.length <= 7
# tiles consists of uppercase English letters.


class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        
        import itertools
        l = range(len(tiles))
        dic = {}
        for i in range(1,len(l) + 1):
            for j in itertools.permutations(l, i):
                v = ''
                for k in j:
                    v += tiles[k]
                if v not in dic:dic[v] = 1
        return len(dic)