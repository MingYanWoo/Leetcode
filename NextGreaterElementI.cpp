#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> retVal;
        for (int i = 0; i < (int)findNums.size(); ++i) {
            int index = 0;
            bool flag = true;
            while (nums[index] != findNums[i]) index++;
            for ( ; index < nums.size(); ++index) {
                if (nums[index] > findNums[i]) {
                    retVal.push_back(nums[index]);
                    flag = false;
                    break;
                }
            }
            if (flag) retVal.push_back(-1);
        }
        return retVal;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}