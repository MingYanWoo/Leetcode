// 面试题 17.11. 单词距离

// 有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

// 示例：

// 输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
// 输出：1
// 提示：

// words.length <= 100000



class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int i = INT_MIN / 2, j = INT_MAX / 2;
        int ans = INT_MAX;
        for(int k = 0; k < words.size(); k++) {
            if(words[k] == word1) {
                i = k;
            }else if(words[k] == word2) {
                j = k;
            }
            ans = min(abs(j - i), ans);
        }
        return ans;
    }
};