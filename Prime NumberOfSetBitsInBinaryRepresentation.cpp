#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int i = L; i <= R; ++i) {
            vector<int> vec;
            int j = i;
            while (j != 0) {
                vec.push_back(j%2);
                j /= 2;
            }
            
            int prime = 0;
            for (int k = 0; k < vec.size(); ++k) {
                if (vec[k] == 1) {
                    prime++;
                }
            }
            if (prime == 1) {
                continue;
            }
            bool flag = true;
            for (int s = 2; s < prime; ++s) {
                if (prime % s == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    A.countPrimeSetBits(6, 10);
    return 0;
}