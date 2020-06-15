// 面试题 10.05. 稀疏数组搜索

// 稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

// 示例1:

//  输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
//  输出：-1
//  说明: 不存在返回-1。
// 示例2:

//  输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
//  输出：4
// 提示:

// words的长度在[1, 1000000]之间



class Solution {
public:
    int findString(vector<string>& words, string s) {
        int i = 0, j = words.size() - 1;
        while(i <= j) {
            while(i <= j && words[i].empty()) i++;  // 保持两端非空
            while(i <= j && words[j].empty()) j--;
            int mid = (i + j) >> 1;
            while(mid < j && words[mid].empty()) mid++;
            if(words[mid] == s) {
                return mid;
            }else {
                if(words[mid] < s) i = mid + 1;
                else j = mid - 1;
            }
        }
        return -1;
    }
};