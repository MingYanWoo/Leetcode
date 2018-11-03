// 387.First Unique Character in a String

// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.


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
    int firstUniqChar(string s) {
        if (s.size() == 0) {
            return -1;
        }
        vector<int> record(26, 0);
        for (auto c : s) {
            record[c-'a'] += 1;
        }
        int i;
        for (i = 0; i < s.size(); i++) {
            if ((record[s[i]-'a']) == 1) {
                break;
            }
            if (i == s.size()-1) {
                return -1;
            }
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    cout << A.firstUniqChar("loveleetcode") << endl;
    return 0;
}