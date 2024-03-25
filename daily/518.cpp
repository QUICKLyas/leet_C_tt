//
// Created by Administrator on 2024/3/25.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    /**
     *
     * @param amount
     * @param coins
     * @return
     */
    int change(int amount, vector<int> & coins) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        for (auto & coin : coins) {
            for (int index = coin; index < amount + 1; index++) {
                dp[index] += dp[index - coin];
                cout << index - coin << " " << dp[index-coin] << endl;
            }
        }
        return dp[amount];
    }
};