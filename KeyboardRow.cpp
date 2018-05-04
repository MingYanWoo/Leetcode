#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> a1{'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        set<char> a2{'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        set<char> a3{'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        vector<string> retVal;
        for (auto word : words) {
            if ((a1.find(word[0]) != a1.end())) {
                bool flag = true;
                for (auto s : word) {
                    if (a1.find(s) == a1.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) retVal.push_back(word);
            }else if ((a2.find(word[0]) != a2.end())) {
                bool flag = true;
                for (auto s : word) {
                    if (a2.find(s) == a2.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) retVal.push_back(word);
            }else if ((a3.find(word[0]) != a3.end())) {
                bool flag = true;
                for (auto s : word) {
                    if (a3.find(s) == a3.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag == true) retVal.push_back(word);
            }
        }
        return retVal;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}