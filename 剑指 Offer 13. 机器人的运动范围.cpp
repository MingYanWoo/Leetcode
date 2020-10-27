// 剑指 Offer 13. 机器人的运动范围

// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

// 示例 1：

// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：

// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：

// 1 <= n,m <= 100
// 0 <= k <= 20




class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push(pair<int,int>{0, 0});
        vis[0][0] = 1;
        int res = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || vis[new_x][new_y] == 1 || getV(new_x) + getV(new_y) > k)   continue;
                q.push(pair<int,int>{new_x, new_y});
                vis[new_x][new_y] = 1;
            }
            res++;
        }
        return res;
    }

    int getV(int v) {
        int res = 0;
        while(v > 0) {
            res += v % 10;
            v /= 10;
        }
        return res;
    }
};