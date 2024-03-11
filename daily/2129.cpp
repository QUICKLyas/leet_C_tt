//
// Created by Administrator on 2024/3/11.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 2129 将标题字母大写
     * 如果单词的长度为1 和 2 该单词都小写
     * 单词首字母大写 返回大写后的title
     * 1 <= title.length <= 100
     * title 由单个空格隔开的单词组成，且不含有任何前导或后缀空格。
     * 每个单词由大写和小写英文字母组成，且都是 非空 的。
     * @param title
     * @return
     */
    string capitalizeTitle (string title) {
        // 48 65 97 = 32
        int sLength = title.length();
        if (97 <= title[0]) { // 如果第一个单词为小写单词，默认转换为大写单词
            title[0] -= 32;
        }
        int wCnt = 1;
        for (int i = 1 ; i < sLength ; i++) {
            wCnt++;
            cout << wCnt << " " << title[i] << " " << title << endl;
            if (title[i] != 32 ) {
                if (title[i-1] != 32) {
                    if (97 <= title[i]){ // 如果当前的单词字母是小写，那么直接跳过
                        continue;
                    } else {
                        title[i] += 32;
                    }
                } else {
                    if (97 <= title[i]) {
                        title[i] -= 32;
                    }
                }
            } else {
                if (wCnt <= 2) {
                    title[i-wCnt+1] += 32; // 将这个单词首字母重新设置为小写
                }
                wCnt = 0;
                // 重新设置记录单词长度的计数器设置为0
            }
        }
        if (wCnt <= 3) {
            title[sLength - wCnt] +=32;
        }
        return title;
    }
};

int main () {
    string s = "First leTTeR of EACH Word";
    Solution sol ;
    string s1 = sol.capitalizeTitle(s);
    cout << s << endl << s1;
}