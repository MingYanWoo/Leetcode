# 79. 单词搜索
# 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

# 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

# 示例:

# board =
# [
#   ['A','B','C','E'],
#   ['S','F','C','S'],
#   ['A','D','E','E']
# ]

# 给定 word = "ABCCED", 返回 true
# 给定 word = "SEE", 返回 true
# 给定 word = "ABCB", 返回 false
 

# 提示：

# board 和 word 中只包含大写和小写英文字母。
# 1 <= board.length <= 200
# 1 <= board[i].length <= 200
# 1 <= word.length <= 10^3


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int p, int x, int y) {
        if(board[x][y] != word[p]) {
            return false;
        }
        if(p == word.size()-1) {
            return true;
        }
        char tmp = board[x][y];
        board[x][y] = '0';
        if((x > 0 && dfs(board, word, p+1, x-1, y)) ||
        (y > 0 && dfs(board, word, p+1, x, y-1)) ||
        (x < board.size()-1 && dfs(board, word, p+1, x+1, y)) ||
        (y < board[0].size()-1 && dfs(board, word, p+1, x, y+1))) {
            return true;
        }
        board[x][y] = tmp;
        return false;
    }
};