// 面试题 08.07. 无重复字符串的排列组合

// 无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

// 示例1:

//  输入：S = "qwe"
//  输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
// 示例2:

//  输入：S = "ab"
//  输出：["ab", "ba"]
// 提示:

// 字符都是英文字母。
// 字符串长度在[1, 9]之间。



class Solution {
public:
    vector<string> permutation(string S) {
        set<string> set;
        vector<string> res;
        string temp = "";
        dfs(S, temp, res, set);
        return res;
    }

    void dfs(string S, string temp, vector<string>& res, set<string> set) {
        if(S.empty()) {
            res.push_back(temp);
            set.insert(temp);
            return;
        }

        for(int i = 0; i < S.size(); i++) {
            if(set.find(temp+S[i]) == set.end())
                dfs(S.substr(0, 0+i)+S.substr(0+i+1, S.size()-0-i), temp+S[i], res, set);
        }
    }
};
