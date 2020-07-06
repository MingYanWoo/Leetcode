// 面试题 04.01. 节点间通路

// 节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

// 示例1:

//  输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
//  输出：true
// 示例2:

//  输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
//  输出 true
// 提示：

// 节点数量n在[0, 1e5]范围内。
// 节点编号大于等于 0 小于 n。
// 图中可能存在自环和平行边。



class Solution {
public:
    vector<int> visit;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<int> temp(n, 0);
        visit = temp;
        vector<vector<int>> adlist(n, vector<int>(0, 0));
        for(int i = 0; i < graph.size(); i++) {
            adlist[graph[i][0]].push_back(graph[i][1]);
        }
        bool res = dfs(adlist, start, target);
        return res;
    }

    bool dfs(vector<vector<int>>& adlist, int start, int target) {
        bool res = false;
        visit[start] = 1;
        for(int i = 0; i < adlist[start].size(); i++) {
            int dst = adlist[start][i];
            if(dst == target) return true;
            if(visit[dst] == 0)
                res = dfs(adlist, dst, target);
            if(res == 1) break;
        }
        return res;
    }
};