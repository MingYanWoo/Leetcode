// 54. 螺旋矩阵
// 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

// 示例 1:

// 输入:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// 输出: [1,2,3,6,9,8,7,4,5]
// 示例 2:

// 输入:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// 输出: [1,2,3,4,8,12,11,10,9,5,6,7]



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int dir = 0;
        int x = 0, y = 0;
        for(int i = 0; i < m * n; i++) {
            ans.push_back(matrix[x][y]);
            visited[x][y] = 1;

            x += dx[dir];
            y += dy[dir];
            if(x >=0 && x < m && y >= 0 && y < n && visited[x][y] == 0) {
                continue;
            }else {
                x -= dx[dir];
                y -= dy[dir];
                dir = (dir + 1) % 4;
                x += dx[dir];
                y += dy[dir];
            }
        }
        return ans;
    }
};