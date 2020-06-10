// 面试题13. 机器人的运动范围
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
        vector<vector<int>> visit(m, vector<int>(n, 0));
        visit[0][0] = 1;
        int ans = 0;
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        queue<pair<int,int>> q;
        pair<int,int> p(0,0);
        q.push(p);
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            ans++;
            for(int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n 
                && visit[new_x][new_y] == 0 && canMove(new_x, new_y, k)) {
                    pair<int,int> p(new_x, new_y);
                    visit[new_x][new_y] = 1;
                    q.push(p);
                }
            }
        }
        return ans;
    }
    bool canMove(int x, int y, int k) {
        int res = 0;
        while(x > 0) {
            res += x % 10;
            x /= 10;
        }
        while(y > 0) {
            res += y % 10;
            y /= 10;
        }
        return res <= k;
    }
};