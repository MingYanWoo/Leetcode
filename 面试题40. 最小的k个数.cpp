// 面试题40. 最小的k个数
// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

// 示例 1：

// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]
// 示例 2：

// 输入：arr = [0,1,2,1], k = 1
// 输出：[0]
 

// 限制：

// 0 <= k <= arr.length <= 10000
// 0 <= arr[i] <= 10000



class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0) return {};
        int start = 0, end = arr.size() - 1;
        int p = partition(arr, start, end);
        while(p != k - 1) {
            if(p > k - 1) {
                end = p - 1;
            }else if(p < k - 1) {
                start = p + 1;
            }
            p = partition(arr, start, end);
        }

        vector<int> res;
        for(int i = 0; i <= p; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }

    int partition(vector<int>& arr, int start, int end) {
        int flag = arr[end];
        while(start < end) {
            while(start < end && arr[start] <= flag) start++;
            arr[end] = arr[start];
            while(start < end && arr[end] > flag) end--;
            arr[start] = arr[end];
        }
        arr[start] = flag;
        return start;
    }
};