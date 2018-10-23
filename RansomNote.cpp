// 383. Ransom Note
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true


#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int r_record[58] = {0};
        int m_record[58] = {0};
        for (auto s : ransomNote) {
            r_record[s-'A'] += 1;
        }
        for (auto s : magazine) {
            m_record[s-'A'] += 1;
        }
        for (int i = 0; i < 58; i++) {
            if (r_record[i] > m_record[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    cout << A.canConstruct("aaa", "aDFasGsBaJ") << endl;
    return 0;
}