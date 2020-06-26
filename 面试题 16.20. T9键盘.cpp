// 面试题 16.20. T9键盘

// 在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。映射如下图所示：



// 示例 1:

// 输入: num = "8733", words = ["tree", "used"]
// 输出: ["tree", "used"]
// 示例 2:

// 输入: num = "2", words = ["a", "b", "c", "d"]
// 输出: ["a", "b", "c"]
// 提示：

// num.length <= 1000
// words.length <= 500
// words[i].length == num.length
// num中不会出现 0, 1 这两个数字




class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        unordered_map<char, set<char>> map{
            {'2', set<char>{'a', 'b', 'c'}},
            {'3', set<char>{'d', 'e', 'f'}},
            {'4', set<char>{'g', 'h', 'i'}},
            {'5', set<char>{'j', 'k', 'l'}},
            {'6', set<char>{'m', 'n', 'o'}},
            {'7', set<char>{'p', 'q', 'r', 's'}},
            {'8', set<char>{'t', 'u', 'v'}},
            {'9', set<char>{'w', 'x', 'y', 'z'}},
        };
        vector<int> valid(words.size(), 1);
        for(int i = 0; i < num.size(); i++) {
            char n = num[i];
            for(int j = 0; j < words.size(); j++) {
                if(valid[j] == 1 && map[n].find(words[j][i]) != map[n].end())
                    continue;
                else
                    valid[j] = 0;
            }
        }
        vector<string> res;
        for(int i = 0; i < valid.size(); i++) {
            if(valid[i] == 1)
                res.push_back(words[i]);
        }
        return res;
    }
};