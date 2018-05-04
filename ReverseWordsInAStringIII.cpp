#include <iostream>#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                end = i - 1;
                swap(s, begin, end);
                begin = i + 1;
            }else if (i == s.size()-1) {
                end = i;
                swap(s, begin, end);
            }
        }
        return s;
    }
private:
    void swap(string &s, int begin, int end) {
        while ((begin != end) && (begin < end)) {
            char temp;
            temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin++;
            end--;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    string s = A.reverseWords("Let's take LeetCode contest");
    cout << s << endl;
    return 0;
}