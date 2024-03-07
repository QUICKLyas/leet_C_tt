// 二位数组edges 长度为n-1，其中edges[i] = [a_i,b_i]，
// 表示树中结点a_i和b_i之间存在一条边，另外给一个整数数组restricted表示受限结点
// 在不访问受限制结点的前提下，返回可以从结点0到达的最多结点数目，
// 注意结点0不会作为受限制结点
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using namespace std;

int num = 7;
vector<vector<int>> es;
vector<int> restrict;

class Solution {
public:
    int reachableNodesBasedOnPython(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // restricted 是 受限制结点
        // 设临时存储边的变量
        // restricted -> list not set
        vector<int> edge;
        map<int,vector<int>> conns;
        int edgesSize = edges.size();
        int restrictedSize =  restricted.size();
        int i = 0;
        int length;
        vector<int>::iterator result;
        for (i=0;i<edgesSize;i++) {
            edge = edges.at(i);
            int startNode = edge.at(0);
            int endNode = edge.at(1);
            if (distance(restricted.begin(),find(restricted.begin(),restricted.end(),endNode)) < restrictedSize
            || distance(restricted.begin(),find(restricted.begin(),restricted.end(),startNode)) < restrictedSize)
                continue;
//            cout << startNode << endNode << endl;
            conns[startNode].push_back(endNode);
            conns[endNode].push_back(startNode);
        }
        queue<int> queue;
        vector<int> visited;
        queue.push(0); // 从0开始进入
        visited.push_back(0);
        while (queue.size() != 0) {
            int node = queue.front();
            queue.pop();
            vector<int> nodes = conns[node]; // 设置数组用于循环
            int size = nodes.size();
            int visitedSize = visited.size();
            for (i=0;i<size;i++) {
                node = nodes.at(i);
                if (distance(visited.begin(),find(visited.begin(),visited.end(),node)) < visitedSize)
                    continue;
//                cout << node << endl;
                visited.push_back(node);
                queue.push(node);

            }
        }
        length = visited.size();
        return length;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> isRestricted(n);
        for (auto x : restricted) {
            isRestricted[x] = 1;
        }
        vector<vector<int>> g(n);
        for (auto &v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int cnt = 0;
        function<void(int,int)> dfs = [&](int x, int f) {
            cnt++;
            for (auto &y: g[x]) {
                if (y != f && !isRestricted[y]) {
                    dfs(y,x);
                }
            }
        };
        dfs(0,-1);
        return cnt;
    }
};

int main () {
    Solution *sol = new Solution();
    vector<int> e;
//  [0,1];
    e.push_back(0);
    e.push_back(1);
    es.push_back(e);
    e.clear();
//    [0,2]
    e.push_back(1);
    e.push_back(2);
    es.push_back(e);
    e.clear();
//    [0,5]
    e.push_back(3);
    e.push_back(1);
    es.push_back(e);
    e.clear();
//    [0,4]
    e.push_back(4);
    e.push_back(0);
    es.push_back(e);
    e.clear();
//    [3,2]
    e.push_back(0);
    e.push_back(5);
    es.push_back(e);
    e.clear();
//   [6,5]
    e.push_back(5);
    e.push_back(6);
    es.push_back(e);
    e.clear();

    restrict.push_back(4);
    restrict.push_back(5);
//    restrict.push_back(1);

    int answer = sol->reachableNodes(7,es,restrict);
    printf("answer: %d", answer);

}