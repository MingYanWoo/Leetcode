// 面试题05. 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

// 示例 1：

// 输入：s = "We are happy."
// 输出："We%20are%20happy."
 

// 限制：

// 0 <= s 的长度 <= 10000



class Solution {
public:
    string replaceSpace(string s) {
        int p1 = s.size() - 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                s += "00";
            }
        }

        int p2 = s.size() - 1;
        while(p1 < p2) {
            if(s[p1] == ' ') {
                s[p2--] = '0';
                s[p2--] = '2';
                s[p2--] = '%';
            }else {
                s[p2--] = s[p1];
            }
            p1--;
        }
        return s;
    }
};