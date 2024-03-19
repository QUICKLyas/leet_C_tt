//
// Created by Administrator on 2024/3/17.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
class Solution{
public:
    /**
     * 有树
     * 包含了n个结点扼断树，标记为0~n-1条n-1条无向边edges列表
     * edges[a_i, b_i]
     * 可选择树中任何一个结点作为根，当选择结点x作为根节点时，设结果的高度为h，在所有可能的树种，具有最小高度的树吗，就是最小树
     * @param n
     * @param edges
     * @return
     */
    vector<int> findMinHeightTrees(int n, vector<vector<int>> & edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> parent(n, -1);
        int x = findLongestNode(0,parent,adj);
        int y = findLongestNode(x,parent,adj);
        vector<int> path;
        parent[x] = -1;
        while(y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m/2 - 1],path[m/2]};
        } else {
            return {path[m/2]};
        }
    }


    int findLongestNode(int u, vector<int> & parent, vector<vector<int> > & adj) {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;
        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto &v : adj[curr]) {
                if (!visit[v]){
                    visit[v] = true;
                    parent [v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }
    // bak
//    vector<int> findMinHeightTrees(int n, vector<vector<int>> & edges) {
//        unordered_map<int,vector<int>> nodeMap(n); // 为每个结点设置一个hash表的根
//        unordered_set<int> nodeSet; // 暂存已经经历的结点
//        int minHeight = n; // 最坏的情况一条直线上的结点
//        for (vector<int> edge : edges) {
//            nodeMap[edge[0]].push_back(edge[1]);
//            nodeMap[edge[1]].push_back(edge[0]); // 构建新的接待你集
//        }
//        int countHeight = 0; // 高度寄存器
//        for (int i = 0; i < n; i++) {
//            nodeSet.clear();
//            bool flag = true;
//            int curNode = i;
//            nodeSet.insert(curNode)
//            while (flag == false) {
//                // 首先确定下一个结点是否是一个没有经过的结点，如果是，那么写入set集，并转移到
//                if (nodeSet.count(nextNode)){
//                    nodeSet.insert(nextNode);
//                }
//
//            }
//        }
//    }
};