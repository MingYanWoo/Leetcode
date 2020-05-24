// 301. 删除无效的括号
// 删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。

// 说明: 输入可能包含了除 ( 和 ) 以外的字符。

// 示例 1:

// 输入: "()())()"
// 输出: ["()()()", "(())()"]
// 示例 2:

// 输入: "(a)())()"
// 输出: ["(a)()()", "(a())()"]
// 示例 3:

// 输入: ")("
// 输出: [""]


class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        // bfs
        int minDel = s.size();
        queue<pair<string,int>> q;
        set<string> set;
        q.push(pair<string,int>(s,0));
        while(!q.empty()) {
            pair<string,int> val = q.front();
            q.pop();
            string tempS = val.first;
            int level = val.second;
            if(minDel == level && isValid(tempS)) {
                res.push_back(tempS);
                continue;
            }
            if(level > minDel) {
                break;
            }
            if(isValid(tempS)) {
                minDel = min(minDel, level);
                res.push_back(tempS);
            }
            for(int i = 0; i < tempS.size(); i++) {
                string newS = tempS.substr(0,i) + tempS.substr(i+1, tempS.size()-i-1);
                if(set.find(newS) == set.end()) {
                    q.push(pair<string,int>(newS,level+1));
                    set.insert(newS);
                }
            }
        }
        return res;
    }

    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> stack;
        for(auto c : s) {
            if(c == '(') {
                stack.push(c);
            }
            else if(c == ')') {
                if(stack.empty()) return false;
                else stack.pop();
            }else {
                continue;
            }
        }
        return stack.empty();
    }
};