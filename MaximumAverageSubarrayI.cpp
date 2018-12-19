// 643. Maximum Average Subarray I

// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

// Example 1:

// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
// Note:

// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0), res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}