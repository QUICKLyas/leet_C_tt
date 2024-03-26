//
// Created by Administrator on 2024/3/26.
//
#include <vector>
#include <queue>
#include <climits>

using namespace std;
class Graph{

public:
    using pii = pair<int,int>;
    // 创建基础图类
    Graph(int n, vector<vector<int>> & edges) {
        this->graph=vector<vector<pii>>(n);
        for(auto &vec: edges) {
            int x = vec[0];
            int y = vec[1];
            int cost = vec[2];
            graph[x].emplace_back(y,cost);
            // 邻接表的表头，是起始点，该头后面接指向的结点，可能有多个，最后其中同时保存到这个点的cost
            // x->(y_1,cost_1)->(y_2,cost_2)
        }
    }

    void addEdge(vector<int> edge) {
        int x = edge[0];
        int y = edge[1];
        int cost = edge[2];
        graph[x].emplace_back(y,cost);
    }
    // 只需要计算node1起点开始的到所有其他结点的距离消耗
    int shortestPath(int node1, int node2)  {
        // 小顶堆
        priority_queue<pii,vector<pii>, greater<pii>> pq;
        vector<int> dist(graph.size(),INT_MAX);// 默认是无穷大，每个index代表一个目标结点的序号
        dist[node1] = 0; // 到自身的距离为0
        pq.emplace(0,node1); // node1 -> node1 : cost = 0
        while(!pq.empty()) {
            auto [cost, cur] = pq.top(); // 自动获取小顶堆的顶部元素组
            pq.pop(); // 删除一个队头元素 cost:node
            if (cur == node2) {
                return cost; //  如果当前结点就是目标结点，那么返回消耗cost
            }
            for (auto [next,nCost] : graph[cur]) { // 循环所有当前结点邻接的下一个结点和cost
                if (dist[next] > cost + nCost) { // 当dist中对应的结点下花销大于当前记录的情况
                    dist[next] = cost + nCost; // 修改对应目的结点下的的花销，更新为最新的最小距离
                    pq.emplace(cost+ nCost,next);// 记录当前的信息到队列中
                }
            }
        }
        return -1;
    }
private:
    vector<vector<pii>> graph;
};