// 43. 字符串相乘
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
// 说明：

// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n1 = num1.size(), n2 = num2.size();
        int n = n1 + n2;
        vector<int> ans(n, 0);

        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                ans[i+j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for(int i = 0; i < n; i++) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] = ans[i] % 10;
        }

        string ansStr = "";
        int i = n;
        while(ans[--i] == 0);
        for(; i >= 0; i--) {
            ansStr += '0' + ans[i];
        }
        return ansStr;
    }
};