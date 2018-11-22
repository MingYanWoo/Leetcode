// 409. Longest Palindrome

// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

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
    int longestPalindrome(string s) {
        int result = 0;
        bool mid = false;
        unordered_map<char, int> map;
        for (auto c : s) ++map[c];
        for (auto it = map.begin(); it != map.end(); ++it) {
            result += it->second;
            if (it->second % 2 == 1) {
                result -= 1;
                mid = true;
            }
        }
        return mid ? result+1 : result;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}
