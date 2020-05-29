// 面试题57 - II. 和为s的连续正数序列
// 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

// 示例 1：

// 输入：target = 9
// 输出：[[2,3,4],[4,5]]
// 示例 2：

// 输入：target = 15
// 输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

// 限制：

// 1 <= target <= 10^5


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target <= 2) return {}; 
        int p1 = 1, p2 = 2;
        vector<vector<int>> res;
        while(p1 <= target / 2 + 1 && p2 <= target / 2 + 1 && p1 < p2) {
            int sum = (p1 + p2) * (p2 - p1 + 1) / 2;
            if(sum < target) {
                p2++;
            }else if(sum > target) {
                p1++;
            }else {
                vector<int> temp;
                for(int i = p1; i <= p2; i++) {
                    temp.push_back(i);
                }
                res.push_back(temp);
                p1++;
                p2++;
            }
        }
        return res;
    }
};