// 42. 接雨水
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

// 示例:

// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6


class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        s.push(0);
        int water = 0;
        for(int i = 1; i < height.size(); i++) {
            while(!s.empty() && height[s.top()] < height[i]) {
                int bottom = s.top();
                s.pop();
                if(s.empty()) break;
                int l = s.top();
                int r = i;
                int h = min(height[i], height[l]) - height[bottom];
                water += (r - l - 1) * h;
            }
            s.push(i);
        }
        return water;
    }
};