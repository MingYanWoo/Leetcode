// 164. 最大间距

// 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

// 如果数组元素个数小于 2，则返回 0。

// 示例 1:

// 输入: [3,6,9,1]
// 输出: 3
// 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
// 示例 2:

// 输入: [10]
// 输出: 0
// 解释: 数组元素个数小于 2，因此返回 0。
// 说明:

// 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
// 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。




struct Bucket {
    bool isUsed = false;
    int min_value = INT_MAX;
    int max_value = INT_MIN;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int maxV = 0, minV = INT_MAX;
        for(auto v : nums) {
            maxV = max(maxV, v);
            minV = min(minV, v);
        }
        int bucketSize = (maxV - minV) / (nums.size() - 1);
        if(bucketSize == 0) bucketSize = 1;
        int numBucket = (maxV - minV) / bucketSize + 1;
        vector<Bucket> buckets(numBucket);
        for(auto v : nums) {
            int pos = (v - minV) / bucketSize;
            buckets[pos].isUsed = true;
            buckets[pos].max_value = max(buckets[pos].max_value, v);
            buckets[pos].min_value = min(buckets[pos].min_value, v);
        }
        int ans = 0;
        int pre = minV;
        for(int i = 0; i < numBucket; i++) {
            if(!buckets[i].isUsed)
                continue;
            ans = max(ans, buckets[i].min_value - pre);
            pre = buckets[i].max_value;
        }
        return ans;
    }
};