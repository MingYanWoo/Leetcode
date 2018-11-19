// 506. Relative Ranks

// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

// Example 1:

// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
// For the left two athletes, you just need to output their relative ranks according to their scores.
// Note:

// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.

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
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = (int)nums.size();
        int count = 0;
        vector<string> result(n, "");
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({nums[i], i});
        }
        for (int i = 0; i < n; i++) {
            int index = q.top().second;
            q.pop();
            if (count == 0) {
                result[index] = "Gold Medal";
            }else if (count == 1) {
                result[index] = "Silver Medal";
            }else if (count == 2) {
                result[index] = "Bronze Medal";
            }else {
                result[index] = to_string(count+1);
            }
            count++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}