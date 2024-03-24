//
// Created by Administrator on 2024/3/24.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    /**
     * 给你一个整数数组 coins ，表示不同面额的硬币；
     * 以及一个整数 amount ，表示总金额。
     * 计算并返回可以凑成总金额所需的 最少的硬币个数 。
     * 如果没有任何一种硬币组合能组成总金额，返回 -1 。
     * 你可以认为每种硬币的数量是无限的。
     * 1 <= coins.length <= 12
     * 1 <= coins[i] <= 2^31 - 1
     * 0 <= amount <= 10^4
     * @param coins
     * @param amount
     * @return
     */
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int) coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i],dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
    }

//        int coinChange(vector<int>& coins, int amount) {
//        for (int i = 0; i < coins.size(); i++) {
//            for (int j = i; j < coins.size(); j++) {
//                if (coins[i] > coins[j]) {
//                    coins[i] += coins[j];
//                    coins[j] = coins[i] - coins[j];
//                    coins[i] -= coins[j];
//                } // sort 从小到大
//            }
//        }
//        for (int i = 0; i < coins.size(); i++) {
//            cout << coins[i] << endl;
//        }
//        int count=0;
//        for (int i = coins.size() - 1; i >=0; i--) {
//            int index = i;
//            while (amount > 0) {
//                if (amount >= coins[index]) {
//                    amount -= coins[index];
//                    count ++ ;
//                } else {
//                    index --;
//                }
//            }
//            if (amount != 0) {
//                count = -1;
//            } else {
//                break;
//            }
//        }
//        return count;
//    }
};