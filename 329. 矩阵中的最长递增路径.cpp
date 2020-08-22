// 329. 矩阵中的最长递增路径

// 给定一个整数矩阵，找出最长递增路径的长度。

// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

// 示例 1:

// 输入: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// 输出: 4 
// 解释: 最长递增路径为 [1, 2, 6, 9]。
// 示例 2:

// 输入: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// 输出: 4 
// 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。



class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())  return 0;
        vector<vector<int>> record(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(matrix, i, j, record));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& record) {
        if(record[x][y] != 0) return record[x][y];
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int res = 1;
        for(int i = 0; i < 4; i++) {
            int newX = dx[i] + x;
            int newY = dy[i] + y;
            if(0 <= newX && newX < matrix.size() && 0 <= newY && newY < matrix[0].size() && matrix[x][y] < matrix[newX][newY]) {
                res = max(res, dfs(matrix, newX, newY, record)+1);
            }
        }
        record[x][y] = res;
        return res;
    }
};