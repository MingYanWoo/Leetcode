// 面试题 08.09. 括号
// 括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

// 说明：解集不能包含重复的子集。

// 例如，给出 n = 3，生成结果为：

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        dfs(n, n, s, res);
        return res;
    }

    void dfs(int l, int r, string s, vector<string>& res) {
        if(l == 0) {
            for(int i = 0; i < r; i++) s += ')';
            res.push_back(s);
            return;
        }
        dfs(l-1, r, s+'(', res);
        if(l < r) {
            dfs(l, r-1, s+')', res);
        }
    }
};