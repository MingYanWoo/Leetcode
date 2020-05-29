// 面试题21. 调整数组顺序使奇数位于偶数前面
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

// 示例：

// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4] 
// 注：[3,1,2,4] 也是正确的答案之一。
 

// 提示：

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10000



class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            while(l < r && nums[l] % 2 != 0) l++;
            while(l < r && nums[r] % 2 == 0) r--;
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }
        return nums;
    }
};