剑指 Offer 66. 构建乘积数组

给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 

提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000




class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> left(n, 1), right(n, 1);
        for(int i = 1; i < n; i++) {
            left[i] = left[i-1] * a[i-1];
        }
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i+1] * a[i+1];
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            res.push_back(left[i] * right[i]);          
        }
        return res;
    }
};