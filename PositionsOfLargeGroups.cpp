// 830. Positions of Large Groups

// In a string S of lowercase letters, these letters form consecutive groups of the same character.

// For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

// Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

// The final answer should be in lexicographic order.

// Example 1:

// Input: "abbxxxxzzy"
// Output: [[3,6]]
// Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
// Example 2:

// Input: "abc"
// Output: []
// Explanation: We have "a","b" and "c" but no large group.
// Example 3:

// Input: "abcdddeeeeaabbbcd"
// Output: [[3,5],[6,9],[12,14]]
 

// Note:  1 <= S.length <= 1000

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        vector<int> temp{0,0};
        int count = 1;
        int start = 0;
        int end = 0;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == S[i-1]) {
                count += 1;
                if (count >= 3 && i == S.length()-1) {
                    temp[0] = start;
                    temp[1] = (int)S.length() - 1;
                    res.push_back(temp);
                }
            }else {
                if (count >= 3) {
                    end = i - 1;
                    temp[0] = start;
                    temp[1] = end;
                    res.push_back(temp);
                }
                count = 1;
                start = i;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<vector<int>> res = A.largeGroupPositions("abcdddeeeeaabbbcd");
    for (auto e : res) {
        for (auto v : e) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}