// 128. 最长连续序列
// 给定一个未排序的整数数组，找出最长连续序列的长度。

// 要求算法的时间复杂度为 O(n)。

// 示例:

// 输入: [100, 4, 200, 1, 3, 2]
// 输出: 4
// 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set;
        int ans = 0;
        for(auto i : nums) set.insert(i);
        for(auto i : nums) {
            int cur = -INT_MAX;
            int len = 0;
            if(i > -INT_MAX && set.find(i-1) == set.end()) {
                cur = i;
                len++;
            }
            while(set.find(cur+1) != set.end()) {
                cur++;
                len++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};