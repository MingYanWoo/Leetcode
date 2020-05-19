// 15. 三数之和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

// 示例：

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return res;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int L = i+1, R = nums.size()-1;
            while(L < R) {
                if(nums[i]+nums[L]+nums[R] == 0) {
                    res.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    while(L<R && nums[L] == nums[++L]);
                    while(L<R && nums[R] == nums[--R]);
                }else if(nums[i]+nums[L]+nums[R] > 0) {
                    R--;
                }else {
                    L++;
                }
            }
        }
        return res;
    }
};