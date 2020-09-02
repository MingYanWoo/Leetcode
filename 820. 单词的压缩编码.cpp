// 820. 单词的压缩编码

// 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

// 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

// 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

// 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 

// 示例：

// 输入: words = ["time", "me", "bell"]
// 输出: 10
// 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 

// 提示：

// 1 <= words.length <= 2000
// 1 <= words[i].length <= 7
// 每个单词都是小写字母 。



class TrieNode {
public:
    TrieNode* children[26];
    int count;
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        count = 0;
    }

    TrieNode* get(char c) {
        if(children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *trie = new TrieNode();
        unordered_map<TrieNode*, int> maps;
        for(int i = 0; i < words.size(); i++) {
            TrieNode *cur = trie;
            for(int j = words[i].size()-1; j >= 0; j--) {
                cur = cur->get(words[i][j]);
            }
            maps[cur] = i;
        }

        int ans = 0;
        for(auto& [node, idx] : maps) {
            if(node->count == 0) {
                ans += words[idx].size() + 1;
            }
        }
        return ans;
    }
};