// 131. 分割回文串
// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

// 返回 s 所有可能的分割方案。

// 示例:

// 输入: "aab"
// 输出:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        backtrack(s, 0, temp, res);
        return res;
    }

    void backtrack(const string& s, int p, vector<string>& temp, vector<vector<string>>& res) {
        if(p >= s.size()) {
            res.push_back(temp);
            return;
        }
        for(int i = p; i < s.size(); i++) {
            if(isValid(s, p, i)) {
                temp.push_back(s.substr(p, i - p + 1));
                backtrack(s, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }

    bool isValid(const string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};