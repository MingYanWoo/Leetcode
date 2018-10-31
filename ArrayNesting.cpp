// 565.Array Nesting

// A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

// Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

// Example 1:

// Input: A = [5,4,0,3,1,6,2]
// Output: 4
// Explanation: 
// A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

// One of the longest S[K]:
// S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
// Note:

// N is an integer within the range [1, 20,000].
// The elements of A are all distinct.
// Each element of A is an integer within the range [0, N-1].

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// TLE
//class Solution {
//public:
//    int arrayNesting(vector<int>& nums) {
//        int longest = 0;
//        set<int> record;
//        for (int i = 0; i < nums.size(); i++) {
//            int pointer = nums[i];
//            record.insert(i);
//            while (record.find(pointer) == record.end()) {
//                record.insert(pointer);
//                pointer = nums[pointer];
//            }
//            longest = longest > record.size() ? longest : record.size();
//            record.clear();
//        }
//        return longest;
//    }
//};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest = 0;
        vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            int count = 0;
            int j = i;
            while (count == 0 || j != i) {
                visited[j] = true;
                j = nums[j];
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<int> arr{5,4,0,3,1,6,2};
    cout << A.arrayNesting(arr) << endl;
    return 0;
}