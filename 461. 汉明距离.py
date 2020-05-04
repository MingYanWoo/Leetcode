# 461. 汉明距离
# 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

# 给出两个整数 x 和 y，计算它们之间的汉明距离。

# 注意：
# 0 ≤ x, y < 231.

# 示例:

# 输入: x = 1, y = 4

# 输出: 2

# 解释:
# 1   (0 0 0 1)
# 4   (0 1 0 0)
#        ↑   ↑

# 上面的箭头指出了对应二进制位不同的位置。


class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        x_list = []
        y_list = []
        while x > 0 or y > 0:
            if x > 0:
                x_list.append(x%2)
                x = x // 2
            else:
                x_list.append(0)
            if y > 0:
                y_list.append(y%2)
                y = y // 2
            else:
                y_list.append(0)
        result = 0
        for i in range(len(x_list)):
            if x_list[i] != y_list[i]:
                result += 1
        return result