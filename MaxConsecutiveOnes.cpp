#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                max = max>count ? max : count;
                count = 0;
            }else {
                count++;
                if (i == (int)nums.size()-1) {
                    max = max>count ? max : count;
                }
            }
        }
        return max;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<int> a{1,0,1,1,0,1};
    cout << A.findMaxConsecutiveOnes(a) << endl;
    return 0;
}