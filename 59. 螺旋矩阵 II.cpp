// 59. 螺旋矩阵 II
// 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3
// 输出:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int dir = 0;
        int x = 0, y = 0;
        for(int i = 1; i <= n*n; i++) {
            ans[x][y] = i;
            
            x += dx[dir];
            y += dy[dir];
            if(x >= 0 && x < n && y >= 0 && y < n && ans[x][y] == 0) {
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