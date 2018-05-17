#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int srecord[26] = {0};
        int trecord[26] = {0};
        int diffIndex = 0;
        for (auto schar : s) {
            int index = schar - 'a';
            srecord[index] += 1;
        }
        for (auto tchar : t) {
            int index = tchar - 'a';
            trecord[index] += 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (srecord[i] != trecord[i]) {
                diffIndex = i;
            }
        }
        return 'a' + diffIndex;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    cout << A.findTheDifference("abcde", "dcaaeb") << endl;
    return 0;
}