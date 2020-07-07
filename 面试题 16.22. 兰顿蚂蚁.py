# 面试题 16.22. 兰顿蚂蚁

# 一只蚂蚁坐在由白色和黑色方格构成的无限网格上。开始时，网格全白，蚂蚁面向右侧。每行走一步，蚂蚁执行以下操作。

# (1) 如果在白色方格上，则翻转方格的颜色，向右(顺时针)转 90 度，并向前移动一个单位。
# (2) 如果在黑色方格上，则翻转方格的颜色，向左(逆时针方向)转 90 度，并向前移动一个单位。

# 编写程序来模拟蚂蚁执行的前 K 个动作，并返回最终的网格。

# 网格由数组表示，每个元素是一个字符串，代表网格中的一行，黑色方格由 'X' 表示，白色方格由 '_' 表示，蚂蚁所在的位置由 'L', 'U', 'R', 'D' 表示，分别表示蚂蚁 左、上、右、下 的朝向。只需要返回能够包含蚂蚁走过的所有方格的最小矩形。

# 示例 1:

# 输入: 0
# 输出: ["R"]
# 示例 2:

# 输入: 2
# 输出:
# [
#   "_X",
#   "LX"
# ]
# 示例 3:

# 输入: 5
# 输出:
# [
#   "_U",
#   "X_",
#   "XX"
# ]
# 说明：

# K <= 100000



class Solution:
    def printKMoves(self, K: int) -> List[str]:
        if K == 0:
            return ['R']
        dirLabel = ['R', 'D', 'L', 'U']
        dirList = [(0,1), (1,0), (0,-1), (-1,0)]
        curDir = 0
        curX = 0
        curY = 1
        blacks = set()
        minX, minY, maxX, maxY = 0,1,0,1

        for _ in range(K):
            if (curX, curY) not in blacks:  # white
                blacks.add((curX, curY))
                curDir = (curDir + 1) % 4
            else:
                blacks.remove((curX, curY))
                curDir = (curDir - 1) % 4
            curX += dirList[curDir][0]
            curY += dirList[curDir][1]
            minX = min(minX, curX)
            minY = min(minY, curY)
            maxX = max(maxX, curX)
            maxY = max(maxY, curY)


        res = []
        for i in range(minX, maxX+1):
            temp = ''
            for j in range(minY, maxY+1):
                if (i, j) == (curX, curY):
                    temp += dirLabel[curDir]
                    continue
                if (i, j) in blacks:
                    temp += 'X'
                else:
                    temp += '_'
            res.append(temp)

        return res

