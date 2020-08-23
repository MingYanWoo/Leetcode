// 面试题 08.13. 堆箱子

// 堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。

// 输入使用数组[wi, di, hi]表示每个箱子。

// 示例1:

//  输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
//  输出：6
// 示例2:

//  输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
//  输出：10
// 提示:

// 箱子的数目不大于3000个。




class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        if(!box.size() || !box[0].size()) return 0;
        sort(box.begin(), box.end(), weight);
        vector<int> dp(box.size(), 0);
        int ans = 0;
        for(int i = 0; i < box.size(); i++) {
            dp[i] = box[i][2];
            for(int j = i - 1; j >= 0; j--) {
                if(box[j][0] > box[i][0] && box[j][1] > box[i][1] && box[j][2] > box[i][2]) {
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    static bool weight(vector<int>& b1, vector<int>& b2) {
        return b1[0] > b2[0];
    }
};