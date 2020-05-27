// 125. 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 示例 2:

// 输入: "race a car"
// 输出: false


class Solution {
    // islower(char c) 是否为小写字母
    // isuppper(char c) 是否为大写字母
    // isdigit(char c) 是否为数字
    // isalpha(char c) 是否为字母
    // isalnum(char c) 是否为字母或者数字
    // toupper(char c) 字母小转大
    // tolower(char c) 字母大转小

public:
    bool isPalindrome(string s) {
        string tmp = "";
        for(auto c : s) {
            if(isalnum(c)) {
                if(islower(c)) {
                    c = toupper(c);
                }
                tmp += c;
            }
        }
        int l = 0, r = tmp.size() - 1;
        while(l < r) {
            if(tmp[l] != tmp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};