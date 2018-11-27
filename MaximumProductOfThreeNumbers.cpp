// 628. Maximum Product of Three Numbers

// Given an integer array, find three numbers whose product is maximum and output the maximum product.

// Example 1:

// Input: [1,2,3]
// Output: 6
// Example 2:

// Input: [1,2,3,4]
// Output: 24
// Note:

// The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

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
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int p = nums[0] * nums[1] * nums[n-1];
        return max(p, nums[n-3]*nums[n-2]*nums[n-1]);
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}
