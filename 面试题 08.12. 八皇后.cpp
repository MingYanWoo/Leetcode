// 面试题 08.12. 八皇后

// 设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整个棋盘的那两条对角线。

// 注意：本题相对原题做了扩展

// 示例:

//  输入：4
//  输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//  解释: 4 皇后问题存在如下两个不同的解法。
// [
//  [".Q..",  // 解法 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // 解法 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> resIdx;
        vector<int> pos;
        dfs(resIdx, pos, 0, n);
        vector<vector<string>> res;
        for(int i = 0; i < resIdx.size(); i++) {
            vector<string> temp(n, string(n, '.'));
            for(int j = 0; j < resIdx[i].size(); j++) {
                int idx = resIdx[i][j];
                temp[j][idx] = 'Q';
            }
            res.push_back(temp);
        }
        return res;
    }

    void dfs(vector<vector<int>>& resIdx, vector<int>& pos, int cur, int n) {
        if(cur == n) {
            resIdx.push_back(pos);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isValid(pos, cur, i)) {
                pos.push_back(i);
                dfs(resIdx, pos, cur+1, n);
                pos.pop_back();
            }            
        }
        return;
    }

    bool isValid(vector<int>& pos, int row, int col) {
        for(int i = 0; i < pos.size(); i++) {
            if(i == row ||
                col == pos[i] ||
                i + pos[i] == row + col ||
                row + pos[i] == col + i) {
                    return false;
                }
        }
        return true;
    }
};