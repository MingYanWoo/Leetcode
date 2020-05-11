# 279. 完全平方数
# 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

# 示例 1:

# 输入: n = 12
# 输出: 3 
# 解释: 12 = 4 + 4 + 4.
# 示例 2:

# 输入: n = 13
# 输出: 2
# 解释: 13 = 4 + 9.


class Solution:
    def numSquares(self, n: int) -> int:
        # bfs
        queue = [(n, 0)]
        visited = set()
        while queue:
            temp, depth = queue.pop(0)
            if temp == 0:
                return depth
            elements = []
            ele = 1
            while ele**2 <= temp:
                elements.append(ele**2)
                ele += 1
            for ele in elements:
                if temp-ele not in visited:     # 剪枝
                    queue.append((temp-ele, depth+1))
                    visited.add(temp-ele)