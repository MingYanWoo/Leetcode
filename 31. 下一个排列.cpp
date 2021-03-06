// 31. 下一个排列
// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

// 必须原地修改，只允许使用额外常数空间。

// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int small = -1, large = -1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                small = i;
                break;
            }
        }
        if(small == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] > nums[small]) {
                large = i;
                break;
            }
        }
        int temp = nums[small];
        nums[small] = nums[large];
        nums[large] = temp;
        reverse(nums.begin()+small+1, nums.end());
    }
};