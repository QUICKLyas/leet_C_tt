//
// Created by Administrator on 2024/3/9.
//
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution{
public:

    /**
     * nums 和 k，可以在任意子序列并且对其全部元素求和
     * 数组的第K大和定义为：可以获得的第第K个最大子序列和
     * 返回第K大和
     * n == nums.length
     * 1 <= n <= 10^5
     * -10^9 <= nums[i] <= 10^9
     * 1 <= k <= min(2000, 2^n)
     * @param nums
     * @param k
     * @return
     */
     long long kSum (vector<int> & nums, int k) {
         int n = nums.size();
         long long total = 0;
         for (int &x : nums) {
             if (x >= 0) {
                 total += x;
             } else {
                 x = -x;
             }
         }
         sort(nums.begin(), nums.end());
         nums.
         long long ret = 0;
         // priority_queue<int> 大根堆
         // priority_queue<int,vector<int>,greater<int>> 最小值优先队列
         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
         pq.push({nums[0], 0});
         for (int j = 2; j <= k; j++) {
             auto [t, i] = pq.top();
             pq.pop();
             ret = t;
             if (i == n - 1) {
                 continue;
             }
             pq.push({t + nums[i + 1], i + 1});
             pq.push({t - nums[i] + nums[i + 1], i + 1});
         }
         return total - ret;
     }
    /**
     * time_out
     * @param nums
     * @param k
     * @return
     */
    long long kSumTimeOut (vector<int> & nums, int k) {
        //1, 优先队列，给定n个非递减
        long long sum = 0;
        for (auto &x : nums) {
            if (x >= 0 ) {
                sum += x;
            } else {
                x = -x;
            }
        } // 求出全部正数的和，就是第一个最大的序列和，同时将所有数据转换为正数，方便使用
        queue <long long> heap; // 用于存储计算过程中的数据，第一个数据为0
        heap.push(0);
        for (auto &x : nums) { // 此时nums中全部都是正数
            int size = heap.size(); // 2 4 8 ...
            for (int i =0;i<size;i++) {
                long long num = heap.front();
                heap.pop();
                heap.push(num + x);
                heap.push(num); // 从队尾加入新的数据
            }
        }
        vector<long long> list_nums;
        // 使用推排序将数据从小到大地排序
        while ( !heap.empty()) {
            list_nums.push_back(heap.front());
            heap.pop();
        }
        int size = list_nums.size() - 1;
        for (int pos = size;pos > 0 ; pos--) {
            for (int i = pos ; i >= 0;i--){
                int index_parents = (i-1) / 2;
                if (list_nums[i] > list_nums[index_parents]) {
                    swap(list_nums[i],list_nums[index_parents]);
                } else {
                    continue;
                }
            }
            // 将最大的数据放到数组最后
            swap(list_nums[0],list_nums[pos]);
        }
        // 此时得到了减去的数据就是我们需要的最大数据
        return sum - list_nums.at(k-1);
    }
    /**
     * @param array
     * @param start
     * @param end
     */
    void max_heapify(vector<int> array, int start,int end) {
        int parent = start;
        int children = start*2+1;
        while (children <= end) {
            int right_children = children;
            if (right_children <= end && array[children] < array[right_children]) {
                children ++ ;
            }
            if (array[parent] > array[children]) {
                return;
            } else {
                swap(array[parent],array[children]);
                parent = children;
                children = parent * 2 + 1;
            }
        }
    }
    /**
     * @param nums
     * @param k
     * @return
     */
    long long kSum_Wrong (vector<int> & nums, int k) {
        //1, 优先队列，给定n个非递减
        int sum = 0;
        for (auto &x : nums) {
            if (x >= 0 ) {
                sum += x;
            } else {
                x = -x;
            }
        } // 求出全部正数的和，就是第一个最大的序列和，同时将所有数据转换为正数，方便使用
        queue <int> heap; // 用于存储计算过程中的数据，第一个数据为0
        heap.push(0);
        for (auto &x : nums) { // 此时nums中全部都是正数
            int size = heap.size(); // 2 4 8 ...
            for (int i =0;i<size;i++) {
                int num = heap.front();
                heap.pop();
                heap.push(num + x);
                heap.push(num); // 从队尾加入新的数据
            }
        }
        vector<int> list_nums;
        // 使用推排序将数据从小到大地排序
        while ( !heap.empty()) {
            list_nums.push_back(heap.front());
            heap.pop();
        }
        int size = list_nums.size() - 1;
        for (int i = size/2 -1;i >= 0;i--) {
            max_heapify(list_nums, i,size);
        }
        for (int pos = size;pos >0;pos--) {
            swap(list_nums[0],list_nums[pos]);
            max_heapify(list_nums,0,pos-1);
        }
        // 此时得到了减去的数据就是我们需要的最大数据
        return sum - list_nums.at(k-1);
    }
};

int main () {
    vector <int> tmp;
    tmp.push_back(-2);
    tmp.push_back(2);
    tmp.push_back(4);
    Solution sol;
    sol.kSum(tmp,5);
}