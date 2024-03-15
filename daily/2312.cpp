//
// Created by Administrator on 2024/3/15.
//
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;
class Solution{
public:
    /**
     * m, n 表示木块高和宽，同时二位数组prices，
     * 其中prices[i] = [h_i, w_i prices_i]
     * 沿垂直方向按高度 完全 切割木块，或 沿水平方向按宽度 完全 切割木块
     * 在将一块木块切成若干小木块后，你可以根据 prices 卖木块。
     * 你可以卖多块同样尺寸的木块。你不需要将所有小木块都卖出去。
     * 你 不能 旋转切好后木块的高和宽。
     * 请你返回切割一块大小为 m x n 的木块后，能得到的 最多 钱数。
     * 1 <= m, n <= 200
     * 1 <= prices.length <= 2 * 10^4
     * prices[i].length == 3
     * 1 <= hi <= m
     * 1 <= wi <= n
     * 1 <= pricei <= 10^6
     * @param m
     * @param n
     * @param prices
     * @return
     */
    long long sellingWood(int m, int n, vector<vector<int>> & prices) {
        // prices[i] = [h_i, w_i prices_i]
        int answer;
        // height 方向的切割
        // wight 方向的切割
        auto pair_hash = [fn=hash<int>()] (const pair<int, int> & o) -> size_t{
            return (fn(o.first) <<  16) ^ fn(o.second);
        };
        // 构建pair作为见key
        unordered_map<pair<int, int>, int, decltype(pair_hash)> value (0, pair_hash);
        vector<vector<long long>> memo (m+1, vector<long long>(n+1, -1));
        // 构建方法
        function<long long(int, int)> dfs = [&](int x, int y) -> long long {
            if (memo[x][y] != -1) {
                return memo[x][y];
            }

            long long ret = value.count({x, y}) ? value[{x, y}]:0);
            if (x > 1) {
                for (int i = 1; i < x; i++) {
                    ret = max(ret, dfs (i, y) + dfs(x-i, y));
                }
            }
            if (y > 1) {
                for (int j = 1; j < y ; j ++) {
                    ret = max(ret, dfs (x,j) + dfs (x,y-j));
                }
            }
            return memo[x][y] = ret;
        };

        for (int i = 0; i < prices.size() ; ++i) {
            value[{prices[i][0], prices[i][1]}] = prices[i][2];
        }
        return dfs(m,n);
    }
};