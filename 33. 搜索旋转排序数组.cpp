// 33. 搜索旋转排序数组
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 示例 1:

// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:

// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) {
            if(nums[0] == target) {
                return 0;
            }else {
                return -1;
            }    
        }
        int start = 0, end = nums.size()-1;
        int mid = start + (end - start) / 2;
        int sw = -1;
        while(start <= end) {
            if(nums[mid] >= nums[0]) {
                if(mid+1 < nums.size()) {
                    if(nums[mid+1] < nums[mid]) {
                        sw = mid;
                        break;
                    }
                    start = mid + 1;
                }else {
                    sw = mid;
                    break;
                }
            }else {
                if(nums[mid-1] > nums[mid]) {
                    sw = mid - 1;
                    break;
                }else {
                    end = mid - 1;
                }
            }
            mid = start + (end - start) / 2;
        }
        cout << sw << endl;
        if(target >= nums[0]) {
            start = 0;
            end = sw;
        }else {
            start = sw + 1;
            end = nums.size()-1;
        }
        mid = start + (end - start) / 2;
        while(start <= end) {
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }
};