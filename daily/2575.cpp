//
// Created by Administrator on 2024/3/7.
// 从0开始的字符串word，长度为n，从0-9的主子组成，给出一个整数m
// word 的可除整数组div 是一个长度为n的整数数组，满足：
// word[0,...i]所表示的数值能被m整除，div[i]=1
// 否则div[i] = 0
// 返回word的可整除数组
// n:[1,10^5] 位数
// word.length == n
// word 是一个数字，整数 被除数
// m:[1,10^9] 除数
//
//

#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> answer;
        long long cur = 0;
        // 类似：for item in items:
        for (char & c : word) {
            cur = ((cur * 10) + (c-'0')) % m; // 除余方法
            answer.push_back(cur == 0?1:0);
        }
        return answer;
//        for (int i=word.length()-1 ; i>=0 ; i--) {
//            cur = (word.at(i) - '0') % m
//        }

    }
};


class S_2580 {
public:
    static constexpr int mod = 1e9+7;
    int countWays(vector<vector<int>> & ranges) {
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();
        long long res= 1 ;
        for (int i = 0; i < n;) {
            int r = ranges[i][1];
            int j = i+1;
            while (j < n && ranges[j][0] <= r) {
                r = max(r,ranges[j][1]);
                j ++;
            }
            res = res * 2 %mod;
            i =j;
        }
        return res;
    }

};
