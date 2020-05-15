// # 221. 最大正方形
// # 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

// # 示例:

// # 输入: 

// # 1 0 1 0 0
// # 1 0 1 1 1
// # 1 1 1 1 1
// # 1 0 0 1 0

// # 输出: 4


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }else {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }else {
                        dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    }
                }
            }
        }
        int result = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result = dp[i][j] > result ? dp[i][j] : result;
            }
        }
        return result*result;
    }
};