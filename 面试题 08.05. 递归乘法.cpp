// 面试题 08.05. 递归乘法

// 递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。

// 示例1:

//  输入：A = 1, B = 10
//  输出：10
// 示例2:

//  输入：A = 3, B = 4
//  输出：12
// 提示:

// 保证乘法范围不会溢出


class Solution {
public:
    int multiply(int A, int B) {
        int res = 0;
        if(A == 1) return B;
        if(A == 0) return res;
        if(A % 2 != 0) {
            int A1 = (A - 1) >> 1;
            res = multiply(A1+1, B) + multiply(A1, B);
        }else {
            A >>= 1;
            res = multiply(A, B) << 1;
        }
        return res;
    }
};