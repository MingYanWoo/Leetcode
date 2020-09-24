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



// K Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 3, 0, 0);
    }

    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target) {
        int sz = nums.size();
        vector<vector<int>> res;
        if(n < 2 || sz < n) return res;
        if(n == 2) {
            int left = start, right = sz - 1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                int leftV = nums[left], rightV = nums[right];
                if(sum < target) {
                    while(left < right && nums[left] == leftV) left++;
                }else if(sum > target) {
                    while(left < right && nums[right] == rightV) right--;
                }else {
                    res.push_back({nums[left], nums[right]});
                    while(left < right && nums[left] == leftV) left++;
                    while(left < right && nums[right] == rightV) right--;
                }
            }
        }else {
            for(int i = start; i < sz; i++) {
                auto sub = nSum(nums, n-1, i+1, target-nums[i]);

                for(auto s : sub) {
                    s.push_back(nums[i]);
                    res.push_back(s);
                }
                while(i < sz - 1 && nums[i] == nums[i+1]) i++;
            }
        }
        return res;
    }
};