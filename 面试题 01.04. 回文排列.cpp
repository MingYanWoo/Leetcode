// 面试题 01.04. 回文排列

// 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

// 回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

// 回文串不一定是字典当中的单词。

 

// 示例1：

// 输入："tactcoa"
// 输出：true（排列有"tacocat"、"atcocta"，等等）



class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> map;
        for(auto c : s) {
            map[c]++;
        }
        int odd = 0;
        for(unordered_map<char,int>::iterator it = map.begin(); it != map.end(); it++) {
            if(it->second % 2 != 0) odd++;
        }
        return odd < 2;
    }
};