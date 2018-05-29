// 349. Intersection of Two Arrays

// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> record;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    record.insert(nums1[i]);
                    break;
                }
            }
        }
        vector<int> res;
        for (auto i : record) {
            res.push_back(i);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}