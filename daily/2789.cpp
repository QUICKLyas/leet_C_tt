//
// Created by Administrator on 2024/3/14.
//
#include <vector>

using namespace std;
class Solution {
public:
    /**
     * 选中一个同时满足 0 <= i < nums.length - 1
     * 和 nums[i] <= nums[i + 1] 的整数 i 。
     * 将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，
     * 并从数组中删除元素 nums[i]
     * 1 <= nums.length <= 10^5
     * 1 <= nums[i] <= 10^6
     * @param nums
     * @return
     */
    long long maxArrayValue(vector<int>& nums) {
        long long sum = nums.back();// 获得最后一个数字
        for (int i = nums.size()-2; i >= 0 ; i--) {
            // 如果当前的数字比后面的数字的和小 则求和，并向前移动
            sum = nums[i] <= sum ? nums[i] + sum : nums[i];
        }
        return sum;
    }
};