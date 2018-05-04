#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> returnVec(S.size(), 0);
        int eIndex = INT_MIN/2;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) eIndex = i;
            returnVec[i] = i - eIndex;
        }
        eIndex = INT_MAX/2;
        for (int i = (int)S.size()-1; i >= 0; i--) {
            if (S[i] == C) eIndex = i;
            returnVec[i] = min(eIndex - i, returnVec[i]);
        }
        return returnVec;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<int> a = A.shortestToChar("loveleetcode", 'e');
    for (auto s : a) {
        cout << s << endl;
    }
    return 0;
}