// 面试题38. 字符串的排列
// 输入一个字符串，打印出该字符串中字符的所有排列。

 

// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

// 示例:

// 输入：s = "abc"
// 输出：["abc","acb","bac","bca","cab","cba"]
 

// 限制：

// 1 <= s 的长度 <= 8



class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        unordered_set<string> set;
        dfs(s, "", res, set);
        return res;
    }

    void dfs(string s, string temp, vector<string>& res, unordered_set<string>& set) {
        if(s.empty()) {
            if(set.find(temp) == set.end()) {
                set.insert(temp);
                res.push_back(temp);
            }
            return;
        }
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            s.erase(s.begin()+i);
            dfs(s, temp + c, res, set);
            s.insert(s.begin()+i, c);
        }
    }
};