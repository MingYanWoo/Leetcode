#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> returnVec;
        int numOfLines = 0;
        int numOfUnits = 0;
        for (auto s : S) {
            int index = s - 'a';
            numOfUnits += widths[index];
            if (numOfUnits > 100) {
                numOfLines += 1;
                numOfUnits = widths[index];
            }
        }
        if (numOfUnits != 0) numOfLines++;                  // 行内还有字符，行数加1
        returnVec.push_back(numOfLines);
        returnVec.push_back(numOfUnits);
        return returnVec;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}