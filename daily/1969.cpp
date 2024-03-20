//
// Created by Administrator on 2024/3/20.
//
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
