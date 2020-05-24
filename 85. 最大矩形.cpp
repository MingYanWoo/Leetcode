// 85. 最大矩形
// 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

// 示例:

// 输入:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// 输出: 6


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(m, vector(n, vector<int>(3, 0)));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 && j == 0) {
                        dp[i][j] = {1,1,1};
                    }else if(i == 0) {
                        dp[i][j] = {dp[i][j-1][0] + 1, 1, dp[i][j-1][2] + 1};
                    }else if(j == 0) {
                        dp[i][j] = {1, dp[i-1][j][1] + 1, dp[i-1][j][2] + 1};
                    }else {
                        dp[i][j][0] = dp[i][j-1][0] + 1;
                        dp[i][j][1] = dp[i-1][j][1] + 1;

                        int col_min = dp[i][j][0];
                        int row = dp[i][j][1];
                        for(int k = 0; k < row; k++) {
                            col_min = min(col_min, dp[i-k][j][0]);
                            dp[i][j][2] = max(dp[i][j][2], col_min * (k + 1));
                        }
                    }
                }
                ans = max(ans, dp[i][j][2]);
            }
        }
        return ans;
    }
};