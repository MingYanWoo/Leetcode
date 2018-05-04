#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainMap;
        vector<string> returnVec;
        for (auto domain : cpdomains) {
            int i = (int)domain.find(" ");                   //找到空格的下标
            int nums = stoi(domain.substr(0, i));
            string eachDomain = domain.substr(i+1, domain.size());
            for (int i = (int)eachDomain.size()-1; i >= 0; i--) {
                if (eachDomain[i] == '.') {
                    domainMap[eachDomain.substr(i+1, eachDomain.size()-1)] += nums;
                }else if (i == 0) {
                    domainMap[eachDomain] += nums;
                }
            }
        }
        for (auto domain : domainMap) {
            returnVec.push_back(to_string(domain.second)+" "+domain.first);
        }
        return returnVec;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> strs = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution A = Solution();
    vector<string> s = A.subdomainVisits(strs);
    for (auto sa : s) {
        cout << sa << endl;
    }
    return 0;
}