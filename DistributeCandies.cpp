#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for (int candy : candies) s.insert(candy);
        return min(s.size(), candies.size() / 2);
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}