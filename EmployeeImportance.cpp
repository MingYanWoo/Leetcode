#include <iostream>
#include <vector>
using namespace std;


 // Employee info
 class Employee {
 public:
 // It's the unique ID of each node.
 // unique id of this employee
 int id;
 // the importance value of this employee
 int importance;
 // the id of direct subordinates
 vector<int> subordinates;
 };
 
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int importance = 0;
        for (auto e : employees) {
            if (e->id == id) {
                importance += e->importance;
                for (auto subid : e->subordinates) {
                    importance += getImportance(employees, subid);
                }
            }
        }
        return importance;
    }
};

int main(int argc, const char * argv[]) {
    Solution A = Solution();
    return 0;
}
