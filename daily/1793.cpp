//
// Created by Administrator on 2024/3/19.
//
#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 一个数组nums （0）和一个整数k
     * 子数组(i,j) 分数定义为nim(nums[i], nums[i+1],...,nums[j]*(j-i+1))
     * 一个好 子数组两个端点小标满足i<= k <=j
     * 请返回好的子数组的最大可能分数
     * 1 <= nums.length <= 10^5
     * 1 <= nums[i] <= 2 * 10^4
     * 0 <= k < nums.length
     * @param nums
     * @param k
     * @return
     */
    int maximumScore(vector<int> & nums, int k) {
        int n = nums.size();
        int left = k - 1, right = k + 1;
        int answer = 0, tmpAnswer = 0;
        for (int i = nums[k];;--i) { // 这里每次削减左后一点过会见到最后需要的最小值
            // 出现比比当前的请开给你更小的数值，则跳过小面的循环
            while (left >=0 && nums[left] >= i) {
                -- left; // 此时左指针变化，说明，上一个元素比中间值大，不用考虑left-right的分组
            }
            while (right < n && nums[right] >= i) {
                ++ right; // 此时右指针变化，说明，上一个元素比中间值大，不用考虑left-right的分组
            }
            answer = max(answer, (right - left - 1)*i);

            // 因为此时的结果是k位置的数据的得分，所以只有数据见到最后我们呢需要的结果才能得到最后的结果
            if (left == -1 && right == n) {
                break; // 说明此时的范围已经越界，不需要再扩大数组范围了
            }
        }
        return answer;
    }
};
//int minNum = numeric_limits<int>::max();
//int maxNum = numeric_limits<int>::min();
//int answer = 0;
///* 从k开始进行计算，这个时候，子数组中只有一个数字k且此时的weight = 0 + 1
// * 且一定是大于 1 的，所以影响最后得分的就是数组中的最小值，
// * 我们需要使得 好数组中，最小值尽量的大，且长度尽量的大
// * 假设最大数组为原数组，此时，最小值固定，且长度固定，我们需要确定缩小数组后，最小数值书否增大，
// * 因为如果最小值 不变大，那么分数身份本身是始终在变小的
// */
//int i = 0,j = nums.size()-1;
//int weight = j -i + 1;
//for (int index=i; index < j; index++) { // 找到其中最小值改变的情况
//minNum = min(minNum,nums[index]);
//maxNum = max(maxNum,nums[index]); // 同步记录其中最大数值
//}
//
//answer = minNum * weight; // 得到当前基本的得分情况
//cout<< "answer-1: " <<answer;
//// 同步改变j和i的大小
//for (; j>=k; j--) {
//int tmp = maxNum;
//for (int index=k; index <= j; index++) { // 找到其中最小值改变的情况
//tmp = min(tmp,nums[index]);
//}
//if (tmp != minNum) {
//auto tmpAnswer = tmp * (j-i+1);
//if (tmpAnswer > answer){
//answer = tmpAnswer;
//minNum = tmp;
//}
//}
//for (; i<=k; i++) {
//tmp = maxNum;
//for (int index=k; index >= i; index--) { // 找到其中最小值改变的情况
//tmp = min(tmp,nums[index]);
//}
//if (tmp != minNum) {
//auto tmpAnswer = tmp * (j - i + 1);
//if(tmpAnswer > answer) {
//answer = tmpAnswer;
//minNum = tmp;
//}
//}
//}
//}
//return answer;

class S_1786 {
public:
    /**
     * 现有一个加权无向连通图。给你一个正整数 n ，
     * 表示图中有 n 个节点，并按从 1 到 n 给节点编号；
     * 另给你一个数组 edges ，其中每个 edges[i] = [ui, vi, weighti]
     * 表示存在一条位于节点 ui 和 vi 之间的边，这条边的权重为 weighti 。
     * 从节点 start 出发到节点 end 的路径是一个形如 [z0, z1, z2, ..., zk] 的节点序列，
     * 满足 z0 = start 、zk = end 且在所有符合 0 <= i <= k-1 的节点 zi 和 zi+1 之间存在一条边。
     * 路径的距离定义为这条路径上所有边的权重总和。用 distanceToLastNode(x)
     * 表示节点 n 和 x 之间路径的最短距离。
     * 受限路径 为满足 distanceToLastNode(zi) > distanceToLastNode(zi+1) 的一条路径，
     * 其中 0 <= i <= k-1 。
     * @param n
     * @param edges
     * @return
     */
    int countRestrictedPaths (int n, vector<vector<int>> & edges) {

    }
private:
    using pii = pair<int,int>;

};