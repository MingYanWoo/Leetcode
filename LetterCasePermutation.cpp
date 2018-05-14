#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 *          a1b2
 *          /  \
 *     a1b2      A1b2
 *     /  \       /  \
 *  a1b2  a1B2  A1b2  A1B2
 *
 */

class Solution {
public:
    vector<string> letterCasePermutation(string S) {        // BFS
        queue<string> q;
        q.push(S);
        for (int i = 0; i < S.length(); ++i) {
            if (isdigit(S[i])) {
                continue;
            }
            int qlen = (int)q.size();
            for (int j = 0; j < qlen; ++j) {
                string front = q.front();
                q.pop();
                
                front[i] = toupper(front[i]);
                q.push(front);
                
                front[i] = tolower(front[i]);
                q.push(front);
            }
        }
        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<string> res =  A.letterCasePermutation("a1b1");
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}