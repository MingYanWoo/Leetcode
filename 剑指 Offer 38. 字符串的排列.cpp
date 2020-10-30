// 剑指 Offer 38. 字符串的排列

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
        int n = s.size();
        vector<int> visited(n, 0);
        vector<string> res;
        unordered_set<string> set;
        dfs(s, visited, res, set, 0, "");
        return res;
    }

    void dfs(string s, vector<int>& visited, vector<string>& res, unordered_set<string>& set, int cur, string temp) {
        int n = s.size();
        if(cur == n && set.find(temp) == set.end()) {
            res.push_back(temp);
            set.insert(temp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(visited[i] == 1) {
                continue;
            }
            visited[i] = 1;
            dfs(s, visited, res, set, cur+1, temp+s[i]);
            visited[i] = 0;
        }
    }
};