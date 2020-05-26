// 16. 最接近的三数之和
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++) {
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int temp = nums[i] + nums[start] + nums[end];
                if(abs(target - temp) <= abs(target - ans)) {
                    ans = temp;
                }
                if(temp > target) {
                    end--;
                }else if(temp < target) {
                    start++;
                }else {
                    return ans;
                }
            }
        }
        return ans;
    }
};