#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int height = (int)matrix.size();
        int width = (int)matrix[0].size();
        for (int i = 0; i < height-1; ++i) {
            for (int j = 0; j < width-1; ++j) {
                if (matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<vector<int>> grid{{14},
        {64}};
    cout << A.isToeplitzMatrix(grid) << endl;;
    return 0;
}