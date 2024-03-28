//
// Created by Administrator on 2024/3/20.
//
#include <vector>

using namespace std;
class Solution{
public:
    /**
     * 给你一个正整数 p 。你有一个下标从 1 开始的数组 nums ，
     * 这个数组包含范围 [1, 2p - 1] 内所有整数的二进制形式（两端都 包含）。
     * 你可以进行以下操作 任意 次：
     * 从 nums 中选择两个元素 x 和 y  。
     * 选择 x 中的一位与 y 对应位置的位交换。对应位置指的是两个整数 相同位置 的二进制位。
     * 比方说，如果 x = 1101 且 y = 0011 ，交换右边数起第 2 位后，
     * 我们得到 x = 1111 和 y = 0001 。
     * 请你算出进行以上操作 任意次 以后，nums 能得到的 最小非零 乘积。
     * 将乘积对 109 + 7 取余 后返回。
     * 注意：答案应为取余 之前 的最小值。
     * @param p
     * @return
     */
    int minNonZeroProduct(int p) {
        if (p == 1) {
            return 1;
        }
        long long mod = 1e9+7;
        long long x = fastPow(2,p,mod)-1;
        long long y = (long long )1 << (p-1);
        return fastPow(x-1,y-1, mod) *x %mod;
    }

    long long fastPow(long long x,long long n,long long mod) {
        long long res = 1;
        for (; n != 0;n >>= 1) {
            if (n & 1) {
                res = res* x %mod;
            }
            x = x * x % mod;
        }
        return res;
    }
};



class S_1997 {
public:
    /**
     * 你需要访问 n 个房间，房间从 0 到 n - 1 编号。
     * 同时，每一天都有一个日期编号，从 0 开始，依天数递增。你每天都会访问一个房间。
     * 最开始的第 0 天，你访问 0 号房间。
     * 给你一个长度为 n 且 下标从 0 开始 的数组 nextVisit 。
     * 在接下来的几天中，你访问房间的 次序 将根据下面的 规则 决定：
     *
     * 假设某一天，你访问 i 号房间。
     * 如果算上本次访问，访问 i 号房间的次数为 奇数 ，
     * 那么 第二天 需要访问 nextVisit[i] 所指定的房间，
     * 其中 0 <= nextVisit[i] <= i 。
     * 如果算上本次访问，访问 i 号房间的次数为 偶数 ，
     * 那么 第二天 需要访问 (i + 1) mod n 号房间。
     *
     * 请返回你访问完所有房间的第一天的日期编号。
     * 题目数据保证总是存在这样的一天。由于答案可能很大，
     * 返回对 109 + 7 取余后的结果。
     * @param nextVisit
     * @return
     */
    int firstDayBeenInAllRooms(vector<int> & nextVisit) {
        int mod = 1e9 + 7;
        int len = nextVisit.size();
        vector<int> dp(len); // 设置存储队列保存第一次情况

        dp[0] = 2;
        for (int i = 1; i < len; i++) {
            int to = nextVisit[i];
            dp[i] = 2 + dp[i-1];

            if (to != 0) {
                dp[i] = (dp[i]-dp[to-1] + mod) % mod;
            }
            dp[i] = (dp[i] + dp[i-1]) % mod;
        }
        return dp[len - 2];

    }
};
