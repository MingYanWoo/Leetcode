// 面试题 08.08. 有重复字符串的排列组合

// 有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

// 示例1:

//  输入：S = "qqe"
//  输出：["eqq","qeq","qqe"]
// 示例2:

//  输入：S = "ab"
//  输出：["ab", "ba"]
// 提示:

// 字符都是英文字母。
// 字符串长度在[1, 9]之间。



class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> res;
        set<string> set;
        string temp = "";
        dfs(S, temp, res, set);
        return res;
    }

    void dfs(string S, string temp, vector<string>& res, set<string>& set) {
        if(S.empty()) {
            res.push_back(temp);
            set.insert(temp);
            return;
        }
        for(int i = 0; i < S.size(); i++) {
            char s = S[i];
            if(set.find(temp+s) == set.end())
                dfs(S.substr(0, i)+S.substr(i+1, S.size()-i), temp+s, res, set);
        }
    }
};