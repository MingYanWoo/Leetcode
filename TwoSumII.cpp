// 167. Two Sum II - Input array is sorted

// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

// Note:

// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.
// Example:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size()-1;
        vector<int> result{0, n};
        while (result[0] <= result[1]) {
            if (numbers[result[0]]+numbers[result[1]] == target) {
                break;
            }else if (numbers[result[0]]+numbers[result[1]] > target) {
                result[1] -= 1;
            }else {
                result[0] += 1;
            }
        }
        result[0] += 1;
        result[1] += 1;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<int> a{2,7,11,15};
    vector<int> s = A.twoSum(a, 22);
    cout << s[0] << s[1] << endl;
    return 0;
}