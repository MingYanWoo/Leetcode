// 面试题53 - I. 在排序数组中查找数字 I
// 统计一个数字在排序数组中出现的次数。

 

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: 0
 

// 限制：

// 0 <= 数组长度 <= 50000

 

// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int start = -1, end = -1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] == target) {
                if(mid == 0 || nums[mid-1] < target) {
                    start = mid;
                    break;
                }else {
                    j = mid - 1;
                }
            }else if(nums[mid] > target) {
                j = mid - 1;
            }else {
                i = mid + 1;
            }
        }
        i = 0;
        j = nums.size() - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(nums[mid] == target) {
                if(mid == nums.size() - 1 || nums[mid+1] > target) {
                    end = mid;
                    break;
                }else {
                    i = mid + 1;
                }
            }else if(nums[mid] > target) {
                j = mid - 1;
            }else {
                i = mid + 1;
            }
        }
        return (start == -1) ? 0 : (end - start + 1);
    }
};