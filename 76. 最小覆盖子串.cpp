// 76. 最小覆盖子串
// 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

// 示例：

// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"
// 说明：

// 如果 S 中不存这样的子串，则返回空字符串 ""。
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count;
        for(auto c : t) count[c]++;
        int minLen = s.size();
        int len = 0;
        string ans = "";
        int l = 0, r = 0;
        while(r < s.size()) {
            count[s[r]]--;
            if(count[s[r]] >= 0) len++;
            while(len == t.size()) {
                if(r - l + 1 <= minLen) {
                    ans = s.substr(l, r - l + 1);
                    minLen = r - l + 1;
                }
                count[s[l]]++;
                if(count[s[l]] > 0) len--;
                l++;
            }
            r++;
        }
        return ans;
    }
};