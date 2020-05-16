// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 如果数组中不存在目标值，返回 [-1, -1]。

// 示例 1:

// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]
// 示例 2:

// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid = start + (end - start) / 2;
        vector<int> result{-1,-1};
        // find min
        while(start <= end) {
            if(nums[mid] == target) {
                if(mid - 1 < 0 || nums[mid-1] != target) {
                    result[0] = mid;
                    break;
                }else {
                    end = mid - 1;
                }
            }else {
                if(nums[mid] < target) {
                    start = mid + 1;
                }else {
                    end = mid - 1;
                }
            }
            mid = start + (end - start) / 2;
        }

        // find max
        start = result[0] == -1 ? 0 : result[0];
        end = nums.size() - 1;
        mid = start + (end - start) / 2;
        while(start <= end) {
            if(nums[mid] == target) {
                if(mid + 1 > nums.size() - 1 || nums[mid+1] != target) {
                    result[1] = mid;
                    break;
                }else {
                    start = mid + 1;
                }
            }else {
                if(nums[mid] < target) {
                    start = mid + 1;
                }else {
                    end = mid - 1;
                }
            }
            mid = start + (end - start) / 2;
        }
        return result;
    }
};