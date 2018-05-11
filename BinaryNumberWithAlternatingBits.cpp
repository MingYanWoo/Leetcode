#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> bin;
        while (n != 0) {
            bin.push_back(n%2);
            n /= 2;
        }
        for (int i = 0; i < bin.size()-1; ++i) {
            if (bin[i] == bin[i+1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}