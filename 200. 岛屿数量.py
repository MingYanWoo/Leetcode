# 200. 岛屿数量
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

# 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

# 此外，你可以假设该网格的四条边均被水包围。

 

# 示例 1:

# 输入:
# 11110
# 11010
# 11000
# 00000
# 输出: 1
# 示例 2:

# 输入:
# 11000
# 11000
# 00100
# 00011
# 输出: 3
# 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        def dfs(i, j):
            if grid[i][j] == '0':
                return
            grid[i][j] = '0'
            for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                new_x = i + dx
                new_y = j + dy
                if 0 <= new_x < m and 0 <= new_y < n:
                    dfs(new_x, new_y)
        result = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    result += 1
                    dfs(i, j)
        return result