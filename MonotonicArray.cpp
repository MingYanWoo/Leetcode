// 896.Monotonic Array

// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

// Return true if and only if the given array A is monotonic.

// Example 1:

// Input: [1,2,2,3]
// Output: true
// Example 2:

// Input: [6,5,4,4]
// Output: true
// Example 3:

// Input: [1,3,2]
// Output: false
// Example 4:

// Input: [1,2,4,5]
// Output: true
// Example 5:

// Input: [1,1,1]
// Output: true
 

// Note:

// 1 <= A.length <= 50000
// -100000 <= A[i] <= 100000

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
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 1) {
            return true;
        }
        bool isIncrease = A[0] >= A[A.size()-1] ? false : true;
        for (int i = 0; i < A.size()-1; i++) {
            if (isIncrease) {
                if (A[i] > A[i+1]) {
                    return false;
                }
            }else {
                if (A[i] < A[i+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<int> arr{1, 1, 0};
    cout << A.isMonotonic(arr) << endl;
    return 0;
}