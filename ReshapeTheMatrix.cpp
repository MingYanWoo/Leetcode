#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = (int)nums.size();
        int cols = (int)nums[0].size();
        if (rows*cols != r*c) {
            return nums;
        }
        vector<vector<int>> retVal(r, vector<int>(c, 0));
        for (int i = 0; i < r*c; ++i) {
            retVal[i/c][i%c] = nums[i/cols][i%cols];
        }
        return retVal;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}
