// 14. 最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:

// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:

// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
// 说明:

// 所有输入只包含小写字母 a-z 。


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) 
            return "";

        string ans = "";
        int j = 0;
        while(true) {
            bool end_flag = false;
            char temp;
            if(j < strs[0].size()) {
                temp = strs[0][j];
            }else {
                break;
            }
            for(int i = 1; i < strs.size(); i++) {
                if(j > strs[i].size()-1 || strs[i][j] != temp) {
                    end_flag = true;
                    break;
                }
            }
            if(end_flag) break;
            ans += temp;
            j++;
        }
        return ans;
    }
};