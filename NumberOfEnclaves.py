class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        moves = [(-1,0), (0,1), (0,-1), (1,0)]

        def dfs(x, y):
            if A[x][y] == 0:
                return
            else:
                A[x][y] = 0
                for i,j in moves:
                    i = x + i
                    j = y + j
                    if 0 <= i < len(A) and 0 <= j < len(A[0]):
                        dfs(i, j)

        for i in range(len(A)):
            dfs(i, 0)
            dfs(i, len(A[0])-1)
        
        for i in range(len(A[0])):
            dfs(0, i)
            dfs(len(A)-1, i)
        
        return sum([sum(a) for a in A])