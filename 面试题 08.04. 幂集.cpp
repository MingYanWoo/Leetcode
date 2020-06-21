// 面试题 08.04. 幂集

// 幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

// 说明：解集不能包含重复的子集。

// 示例:

//  输入： nums = [1,2,3]
//  输出：
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, 0, temp, res);
        return res;
    }

    void dfs(vector<int>& nums, int p, vector<int> temp, vector<vector<int>>& res) {
        if(p == nums.size()) {
            res.push_back(temp);
            return;
        }
        dfs(nums, p+1, temp, res);
        temp.push_back(nums[p]);
        dfs(nums, p+1, temp, res);
    }
};