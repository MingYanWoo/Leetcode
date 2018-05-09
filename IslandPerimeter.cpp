#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int height = (int)grid.size();
        int width = (int)grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }else {
                    int p = 0;
                    if (grid[i-1<0 ? i : i-1][j] != 1 || i-1 < 0) p++;
                    if (grid[i+1>=height ? i : i+1][j] != 1 || i+1 >= height) p++;
                    if (grid[i][j-1<0 ? j : j-1] != 1 || j-1 < 0) p++;
                    if (grid[i][j+1>=width ? j : j+1] != 1 || j+1 >= width) p++;
                    perimeter += p;
                }
            }
        }
        return perimeter;
    }
};
int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<vector<int>> grid{{0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}};
    cout << A.islandPerimeter(grid) << endl;;
    
    return 0;
}