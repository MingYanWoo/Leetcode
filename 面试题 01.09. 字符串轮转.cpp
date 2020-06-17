// 面试题 01.09. 字符串轮转
// 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

// 示例1:

//  输入：s1 = "waterbottle", s2 = "erbottlewat"
//  输出：True
// 示例2:

//  输入：s1 = "aa", s2 = "aba"
//  输出：False
// 提示：

// 字符串长度在[0, 100000]范围内。
// 说明:

// 你能只调用一次检查子串的方法吗？



class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.empty() && s2.empty()) return true;
        if(s1.empty() || s2.empty()) return false;
        string ds1 = s1 + s1;
        int count = 0;
        int i = 0, j = 0;
        while(i < ds1.size()) {
            if(ds1[i] == s2[j]) {
                j++;
                count++;
                if(count == s2.size()) return true;
            }else {
                count = 0;
                j = 0;
            }
            i++;
        }
        return false;
    }
};