// 56. 合并区间
// 给出一个区间的集合，请合并所有重叠的区间。

// 示例 1:

// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:

// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int start = 0, end = 0, t = intervals[0][1];
        while(end < intervals.size()) {
            if(intervals[end][0] <= t) {
                t = max(intervals[end][1], t);
            }else {
                vector<int> inter{intervals[start][0], t};
                result.push_back(inter);
                start = end;
                t = intervals[start][1];
            }
            end++;
        }
        vector<int> inter{intervals[start][0], t};
        result.push_back(inter);
        return result;
    }
};