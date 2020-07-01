// 面试题 16.10. 生存人数

// 给定N个人的出生年份和死亡年份，第i个人的出生年份为birth[i]，死亡年份为death[i]，实现一个方法以计算生存人数最多的年份。

// 你可以假设所有人都出生于1900年至2000年（含1900和2000）之间。如果一个人在某一年的任意时期都处于生存状态，那么他们应该被纳入那一年的统计中。例如，生于1908年、死于1909年的人应当被列入1908年和1909年的计数。

// 如果有多个年份生存人数相同且均为最大值，输出其中最小的年份。

// 示例：

// 输入：
// birth = {1900, 1901, 1950}
// death = {1948, 1951, 2000}
// 输出： 1901
// 提示：

// 0 < birth.length == death.length <= 10000
// birth[i] <= death[i]




class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> res(102, 0);
        for(int i = 0; i < birth.size(); i++) {
            res[birth[i] - 1900]++;
            res[death[i] + 1 - 1900]--;
        }

        int max = 0, idx = 0;
        for(int i = 1; i < res.size(); i++) {
            res[i] = res[i] + res[i-1];
            if(res[i] > max) {
                max = res[i];
                idx = i;
            }
        }
        return 1900 + idx;
    }
};