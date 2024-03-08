//
// Created by Administrator on 2024/3/8.
//
class Solution{
public:
    /**
     * 两个正整数n, target
     * nums.length == n
     * nums 由两两互不相同的正整数组成
     * 在[0,n-1]内，不存在两个不同下表i,j 使得nums[i] + nums[j] == target
     * 返回符合标准的美丽数组所可能具备的最小和，并对结果取模10^9 + 7
     * 1 <= n <= 10^9
     * 1 <= target <= 10^9
     * @param n
     * @param target
     * @return
     */
    int minimumPossibleSum (int n, int target) {
        int minimumPossibleSum (int n, int target) {
            const int mod = 1e9 + 7;
            int m = target / 2;
            if (n <= m) {
                return (long long) (1+n) * n / 2 % mod;
            }
            int m_1 = (target + 1)/2;
            return ((long long) (1+n)*n/2 +
                    (long long ) (n-m)*(m_1-1)) %mod;
        }
    }
};