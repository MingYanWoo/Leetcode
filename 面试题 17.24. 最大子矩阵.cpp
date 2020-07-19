// 面试题 17.24. 最大子矩阵

// 给定一个正整数和负整数组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

// 返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

// 注意：本题相对书上原题稍作改动

// 示例:

// 输入:
// [
//    [-1,0],
//    [0,-1]
// ]
// 输出: [0,1,0,1]
// 解释: 输入中标粗的元素即为输出所表示的矩阵
// 说明：

// 1 <= matrix.length, matrix[0].length <= 200



class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        int sum = INT_MIN;
        vector<int> ans(4, 0);
        vector<int> b(M, 0);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) b[j] = 0;    // 清空b数组
            for(int j = i; j < N; j++) {
                for(int k = 0; k < M; k++) b[k] += matrix[j][k]; 
                int begin = 0, end = 0;
                int curSum = b[0];
                if(curSum > sum) {
                    sum = curSum;
                    ans[0] = i;
                    ans[1] = begin;
                    ans[2] = j;
                    ans[3] = end;
                }
                for(int k = 1; k < M; k++) {
                    if(curSum < 0) {
                        curSum = b[k];
                        begin = k;
                    }else {
                        curSum += b[k];
                    }
                    if(curSum > sum) {
                        sum = curSum;
                        end = k;
                        ans[0] = i;
                        ans[1] = begin;
                        ans[2] = j;
                        ans[3] = end;
                    }
                }
            }
        }
        return ans;
    }
};