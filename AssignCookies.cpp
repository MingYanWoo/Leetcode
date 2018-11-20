// 455. Assign Cookies

// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

// Note:
// You may assume the greed factor is always positive. 
// You cannot assign more than one cookie to one child.

// Example 1:

// Input: [1,2,3], [1,1]

// Output: 1

// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
// You need to output 1.
// Example 2:

// Input: [1,2], [1,2,3]

// Output: 2

// Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
// You have 3 cookies and their sizes are big enough to gratify all of the children, 
// You need to output 2.

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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gn = (int)g.size();
        int sn = (int)s.size();
        int count = 0;
        priority_queue<int, vector<int>, greater<int> > gq;
        priority_queue<int, vector<int>, greater<int> > sq;
        for (int i = 0; i < gn; i++) {
            gq.push(g[i]);
        }
        for (int i = 0; i < sn; i++) {
            sq.push(s[i]);
        }
        while (!gq.empty() && !sq.empty()) {
            int g = gq.top();
            int s = sq.top();
            if (s >= g) {
                gq.pop();
                sq.pop();
                count++;
            }else {
                sq.pop();
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    vector<int> g{1,2,3};
    vector<int> s{1,2};
    cout << A.findContentChildren(g, s) << endl;
    return 0;
}