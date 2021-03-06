// 面试题39. 数组中出现次数超过一半的数字
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

// 示例 1:

// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
// 输出: 2
 

// 限制：

// 1 <= 数组长度 <= 50000



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == ans) {
                count++;
            }else {
                count--;
                if(count == 0) {
                    ans = nums[i];
                    count = 1;
                }
            }
        }
        return ans;
    }
};