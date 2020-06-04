// 面试题29. 顺时针打印矩阵
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

// 示例 1：

// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
// 示例 2：

// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

// 限制：

// 0 <= matrix.length <= 100
// 0 <= matrix[i].length <= 100
// 注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 1));
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int dir = 0;
        int x = 0, y = 0;
        for(int i = 0; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            visit[x][y] = 0;
            x += dx[dir];
            y += dy[dir];
            if(x >= 0 && x < m && y >= 0 && y < n && visit[x][y] != 0) {
                continue;
            }else {
                x -= dx[dir];
                y -= dy[dir];
                dir = (dir + 1) % 4;
                x += dx[dir];
                y += dy[dir];
            }
        }
        return res;
    }
};