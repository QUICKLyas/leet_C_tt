//
// Created by Administrator on 2024/3/10.
//
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 299 猜数字游戏
     * 公牛Bulls猜测的数字中有数字和相应位置都对了
     * 奶牛Cows猜测的数字中数字对了但是位置不多
     * 秘密数字secret 和 猜测数字guesss
     * xAyB A表示公牛，B表示奶牛
     * 1 <= secret.length, guess.length <= 1000
     * secret.length == guess.length
     * secret 和 guess 仅由数字组成
     * @param secret
     * @param guess
     * @return
     */
    string getHint(string secret, string guess) {
        string answer;
        // 遍历字符串
        // 1. secret[i] = guess[i] 这个是Bulls
        // 2. secret[i] != guess[i] 这个时候是可能为Cows
        int bulls = 0; // 出现公牛的次数
        vector<int> sCnt(10),gCnt(10); //0-9 10个数字出现的次数，
        for (int i = 0 ; i < secret.length() ; ++ i) {
            if (secret[i] == guess[i]) {
                ++ bulls;
            } else {
                ++ sCnt[secret[i] - '0']; // secret 中出现这个数字的次数
                ++ gCnt[guess[i] - '0']; // guess中出现这个数字的次数
            }
        } // 比较两个hash计数器中的数字，一般数字都才对了，但是位置有问题，这两个计数器中，出现数字的计数结果应该一致
        // 所以统计最后的结果，是将两个计数器，对应数字出现情况，较少的记录到总的计数器中
        int cows = 0;
        for (int i = 0 ; i < sCnt.size() ; ++ i) {
            cows += min(sCnt[i],gCnt[i]);
        }
        answer = to_string(bulls) + "A" + to_string(cows) + "B";
        return answer;
    }
};