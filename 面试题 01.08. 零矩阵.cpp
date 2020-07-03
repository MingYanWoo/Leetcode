// 面试题 01.08. 零矩阵

// 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

// 示例 1：

// 输入：
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// 输出：
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// 示例 2：

// 输入：
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// 输出：
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row = false, first_col = false;
        for(int i = 1; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                first_row = true;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                first_col = true;
                break;
            }
        }
        if(matrix[0][0] == 0) {
            first_col = true;
            first_row = true;
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(first_row) {
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if(first_col) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};