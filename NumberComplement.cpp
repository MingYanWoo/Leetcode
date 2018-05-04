#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        vector<int> binStr;
        vector<int> comDtr;
        int returnVal = 0;
        while (num != 0) {
            binStr.push_back(num % 2);
            num /= 2;
        }
        for (auto s : binStr) {
            if (s == 1) comDtr.push_back(0);
            else comDtr.push_back(1);
        }
        for (int i = 0; i < comDtr.size(); i++) {
            returnVal += comDtr[i] * pow(2, i);
        }
        return returnVal;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    int a = A.findComplement(16);
    cout << a << endl;
    return 0;
}