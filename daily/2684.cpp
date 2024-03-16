//
// Created by Administrator on 2024/3/16.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 给你一个下标从 0 开始、
     * 大小为 m x n 的矩阵 grid ，矩阵由若干 正 整数组成。
     * 你可以从矩阵第一列中的 任一 单元格出发，按以下方式遍历 grid ：
     * 从单元格 (row, col) 可以移动到
     * (row - 1, col + 1)、(row, col + 1) 和 (row + 1, col + 1)
     * 三个单元格中任一满足值 严格 大于当前单元格的单元格。
     * 返回你在矩阵中能够 移动 的 最大 次数。
     * @param grid
     * @return
     */
    int maxMoves(vector<vector<int>> & grid) {
        int rowSize = grid.size(), colSize = grid[0].size();

        unordered_set <int> rowQ, colQ;
        // 记录每一行的标签index
        for (int i = 0; i < rowSize; i++) {
            rowQ.insert(i);
        }
        for (int colI = 1; colI < colSize; colI++) {
            colQ.clear(); // 清空循环的内容
            for (int rowI : rowQ) {
                for (int rowI2 = rowI - 1; rowI2 <= rowI + 1 ; rowI2 ++ ) {
                    if (0 <= rowI2 && rowI2 < rowSize && grid[rowI][colI-1] < grid[rowI2][colI]) {
                        colQ.insert(rowI2);
                    }
                }
            }
            swap (rowQ, colQ);
            if (rowQ.empty()) {
                return colI - 1;
            }
        }
        return rowSize - 1;
    }
};