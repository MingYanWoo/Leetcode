// 剑指 Offer 51. 数组中的逆序对

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

// 示例 1:

// 输入: [7,5,6,4]
// 输出: 5
 

// 限制：

// 0 <= 数组长度 <= 50000



class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        return mergeSort(nums, temp, 0, n-1);
    }

    int mergeSort(vector<int>& nums, vector<int>& temp, int start, int end) {
        if(start >= end) return 0;
        int mid = (start + end) / 2;
        int left = mergeSort(nums, temp, start, mid);
        int right = mergeSort(nums, temp, mid+1, end);
        int count = 0;
        int i = start, j = mid + 1, k = start;
        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }else {
                count += mid - i + 1;
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = nums[i++];
        }
        while(j <= end) {
            temp[k++] = nums[j++];
        }
        i = start;
        k = start;
        while(i <= end) {
            nums[i++] = temp[k++];
        }
        return count + left + right;
    }
};