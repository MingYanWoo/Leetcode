# 22. 括号生成
# 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

# 示例：

# 输入：n = 3
# 输出：[
#        "((()))",
#        "(()())",
#        "(())()",
#        "()(())",
#        "()()()"
#      ]


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        def dfs(cur, left, right):
            if left == right == 0:
                result.append(cur)
                return
            if left > 0:
                dfs(cur+'(', left-1, right)
            if right > left:
                dfs(cur+')', left, right-1)
        dfs('', n, n)
        return result