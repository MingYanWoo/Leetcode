# 面试题 16.19. 水域大小
# 你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

# 示例：

# 输入：
# [
#   [0,2,1,0],
#   [0,1,0,1],
#   [1,1,0,1],
#   [0,1,0,1]
# ]
# 输出： [1,2,4]
# 提示：

# 0 < len(land) <= 1000
# 0 < len(land[i]) <= 1000

class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        m = len(land)
        n = len(land[0])
        result = []
        tempSum = 1

        def dfs(x, y):
            # if land[x][y] != 0:
            #     return
            nonlocal tempSum
            land[x][y] = -1
            moves = [[-1,-1,-1,0,0,1,1,1],
                    [-1,0,1,-1,1,-1,0,1]]
            for dx,dy in zip(moves[0],moves[1]):
                new_x = x + dx
                new_y = y + dy
                if 0 <= new_x < m and 0 <= new_y < n and land[new_x][new_y] == 0:
                    dfs(new_x, new_y)
                    tempSum = tempSum + 1
        
        for i in range(m):
            for j in range(n):
                if land[i][j] == 0:
                    dfs(i, j)
                    result.append(tempSum)
                    tempSum = 1
        
        return sorted(result)
