#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        int max = 0;
        for (int i = 0; i < rows*cols; ++i) {
            if (grid[i/cols][i%cols] == 1) {
                int count = 0;
                dfs(grid, i/cols, i%cols, rows, cols, count);
                max = count>max ? count : max;
            }
        }
        return max;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols, int &count) {
        if (i < 0 || i > rows-1 || j < 0 || j > cols-1) {
            return;
        }
        if (grid[i][j] == 1) {
            count += 1;
            grid[i][j] = 0;
            dfs(grid, i-1, j, rows, cols, count);
            dfs(grid, i, j+1, rows, cols, count);
            dfs(grid, i+1, j, rows, cols, count);
            dfs(grid, i, j-1, rows, cols, count);
        }
        return;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}