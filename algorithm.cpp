//
// Created by Administrator on 2024/3/7.
//
#include <vector>
#include <climits>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:

    /**
     * 4
     * @param nums1
     * @param nums2
     * @return
     * 4. 寻找正序数组的中位数
     * 给定两个大小分别为m,n的正序数组 nums1 nums2
     * 找出并返回两个正序数组的 中位数， 并返回
     * nums1.length == m
     * nums2.length == n
     * 0 <= m <= 1000
     * 0 <= n <= 1000
     * 1 <= m + n <= 2000
     * -10^6 <= nums1[i], nums2[i] <= 10^6
     */
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        // 中位数的位置通过 j = (m+n+1)/2 - i 确定，
        // 如果nums1过大会造成j为负数，所以需要保证nums是小的那个，
        // 这样就确保了不会超过半数导致j为负数
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2,nums1);
        }
        int m = nums1.size(); // 短的
        int n = nums2.size(); // 长的
        int left=0,right=m;
        int midden_max = 0,midden_min=0; // midden_max 前半部分最大值，midden_min后半部分最小值
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m+n+1)/2 -i;
            int nums1Left = i == 0 ? INT_MIN:nums1[i-1];
            int nums1Right = i == m ? INT_MAX:nums1[i];
            int nums2Left = j == 0 ? INT_MIN:nums2[j-1];
            int nums2Right = j == n ? INT_MAX:nums2[j];


            if (nums1Left <= nums2Right){
                midden_max = max(nums1Left,nums2Left);
                midden_min = min(nums1Right,nums2Right);
                left = i + 1; // 此时左侧旗帜向右侧移动
            } else {
                right = i - 1; // 想左侧移动
            }
        }
        return (m+n)%2 == 0 ? (midden_min + midden_max) / 2.0 : midden_max; // 奇数返回前半部分的最大数值
    }
    /**
     * 123
     * @param prices
     * @return
     * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
     * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
     * prices = [3,3,5,0,0,3,1,4]
     * 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
     * 1 <= prices.length <= 10^5
     * 0 <= prices[i] <= 10^5
     * 五种状态：
     * 未进行操作
     * 只进行了一种操作
     * 进行了一次操作和一次卖操作，完成了一笔交易
     * 再完成了一笔交易的前提下，进行了第二次操作
     * 完成了两种交易
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0; // 负号表示支出
        int buy2 = -prices[0], sell2 = 0;
        // prices = [3,3,5,0,0,3,1,4]
        for (int i = 0;i < n;i++) { // 会随这标记的移动过，改变购买策略
            buy1 = max(buy1,-prices[i]);
            sell1 = max(sell1,buy1 + prices[i]); // 如果不该边，说明之前的购买策略是比较好的，否则重新开始这里的购买策略
            buy2 = max(buy2,sell1-prices[i]); // 这里说明，如果购买花去的前大于新的花销，则说明，不要改变这里的购买策略
            sell2 = max(sell2,buy2+prices[i]);// 这里最后计算表明，最后结果会随着前面的操作而收到影响
        }
        return sell2;
    }
    /**
     * 23 合并K个升序列表
     */
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    /**
     *
     * @param lists
     * @return
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 首先创建一个listNode 的开始结点
        // 1, 顺序合并，很简单 时间复杂度为O(k^2*n) 空间复杂度 O(1)
        // 2, 分支合并，需要实现的，但是由于递归的原因会损耗大量栈空间
        return merge(lists,0,lists.size()-1);
        // 3, 使用有限队列合并

    }
    /**
     * 23-2-1 分支合并
     * @param a
     * @param b
     * @return
     */
    ListNode* mergeTwoList(ListNode *a, ListNode*b) {
        ListNode head, *tail = &head, *aPtr = a,*bPtr = b;// 最新扼断为指针tail
        while (aPtr && bPtr) { // 只要有一个达到结尾，就退出循环
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next; // 统一移动队尾指针到最新的队尾
        }
        tail->next = (aPtr ? aPtr : bPtr); // 如果a链表指针为空，那么b链表直接连接到新链表结尾
        return head.next; // 直接返回第一个数据结点的指针，不返回队头结点
    }
    /**
     * 23-2-2
     * @param lists
     * @param l
     * @param r
     * @return
     */
    ListNode * merge (vector <ListNode*> &lists,int l,int r) {
        if (l == r) return lists[l]; // 如果当左右指针合并，说明这时操作的是同一个链表
        if (l > r) return nullptr; // 如果左侧指针大于右侧指针，说明操作越界
        int mid = (l + r) >> 1 ; //二进制数向右移动，就是除以2
        return mergeTwoList(merge(lists,l,mid), merge(lists,mid+1,r));
        // 二分合并
    }
    /**
     * 1125 最小必要团队
     * @param req_skill
     * @param people
     * @return
     */
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>> & people) {
        // 需要最后扫描的数据，我们应该考虑这张表中元素重复数量，
        // 设置待选人员，每个待选人员存在多少需要的技能，最后团队必须覆盖所有的需求
        // 1, 动态规划
        // 2, 动态规划 + 优化
        int reqSkillSize = req_skills.size(), peopleSize = people.size();
        map <string,int> skillIndex;
        for (int i =0;i<reqSkillSize;++i) {
            skillIndex[req_skills[i]] = i; // 存放需求技能的信息，每个序号代表一种技能，作为技能词典
        }
        vector<vector<int>> dp(1 << reqSkillSize); // 左移表示乘2 ，总共移动了reqSkillSize位数
        // 这里设置了需要的空间
        for (int i =0;i < peopleSize;++i) {
            int curSkill = 0;
            for (string & s: people[i]) {// 查看所有当前这个员工的技能
                curSkill |= 1 << skillIndex[s]; // 或运算到但付钱技能中，如果该技能是需要的，则加入到curSkill
            }
            for (int prev = 0; prev < dp.size(); ++ prev) {
                if (prev > 0 && dp[prev].empty()) continue;
                // 合并当前技能和之前技能
                int comb = prev | curSkill; // 当前技能添加到prev中
                if (comb == prev) continue; // 如果没变化，则跳过
                if (dp[comb].empty() || dp[prev].size() + 1 < dp[comb].size()) {
                    // 如果comb 当前的成员空，跳过，如果旧的team人员加1仍然小于当前的team大小，跳过
                    dp[comb] = dp[prev];
                    // 在comb中的team中加入当前这个用户的编号
                    dp[comb].push_back(i);
                }
            }
        }
        // dp表中最大状态码对应位置下存储的team就是我们需要的队伍
        return dp[(1 << reqSkillSize) -1];
    }
    /**
     * 动态规划 ****
     * 140 单词拆分II
     * @param s
     * @param wordDict
     * @return
     */
    unordered_map<int, vector<string>> answer;
    unordered_set<string> wordSet;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 记忆化搜索
        wordSet = unordered_set<string> (wordDict.begin(), wordDict.end());
        backtrack(s,0); // 从0开始计算
        return answer[0];
    }

    void backtrack(const string & s,int index) {
        if (!answer.count(index)) { // 如果当前的这个index标签不在answer中，进入判断
            if(index == s.size()) { // 如果index 正好为 s的大小，进入
                answer[index] = {""}; // 此时index的位置正好就是字符串末尾，不需要进行切分的操作，直接设置一个""，返回
                return;
            }
            answer[index] = {}; // 设置为空，到这说明，当前标签不等于s的大小
            for (int i = index+1; i <= s.size(); ++i) {
                string word = s.substr(index, i - index); // 字符串切割index开始,划分i-index个数据
                if (wordSet.count(word)) { // 判断当前的单词是否存在这个字典中
                    // 在字典中返回1，则进一步查看这个单词后面的字符串是否还可以进行划分
                    backtrack(s,i); // 继续查看这个标签后面的语句是否构成句子
                    for (const string & succ : answer[i]) { // 循环当前answer这张map
                        // 具有hash表的特性
                        // 在对应切分起始点的hash项下加入word + “ ” + succ
                        // 如果succ为空，那么直接加入word
                        answer[index].push_back(succ.empty() ? word: word + " " + succ);
                    }
                }
            }
        }
    }

    /**
     * 30 串联所有单词的子串 - 关联题 - 438
     * s 和 words words中的字符串 长度相等
     * s 中 串联子串 是指一个包含words中所有字符串以任意顺序排列连接起来的子串
     * 返回所有串联子串在s中的开始索引，串联字串不能连续重复同一个字符
     * 应该是使用words中的所有字符串，组合成为一个新的字符串
     * 1 <= s.length <= 104
     * 1 <= words.length <= 5000
     * 1 <= words[i].length <= 30
     * words[i] 和 s 由小写英文字母组成
     * @param s
     * @param words
     * @return
     */
    vector<int> findSubstring(string s, vector<string> & words) {
        vector <int> answer;
        int wordsCnt = words.size() , wordLength = words[0].size(), sLength = s.size() ;
        for (int i = 0; i < wordLength && i + wordsCnt *  wordLength <= sLength ; ++ i) {
            // 每次i加一，就要重新构建一个hash表 i 小于一个单词的长度，且，i + 所有需要的单词的长度，不能超过本身字符串s的长度
            unordered_map<string, int> differ; // 0 是默认数值
            for (int j = 0; j < wordsCnt ; ++ j) { // 从 s 的 i位置进行hash表构建，数量 为 wordLength
                // 其中每个项目的名字是wordCnt长度的字符串
                ++ differ[s.substr(i + j * wordLength, wordLength)];
                // 这里hash表differ 存储了从i开始，每个以WordLength划分所有的字符串的情况，记录为1
            }
            for (string & word : words) {
                // 遍历words中字符串
                if  ( -- differ[word] == 0) { // 这个表中的对应字符下的数据被减去为0，进入，表示这个单词，在当前划分的串联字符串中出现了
                    differ.erase(word); // 删除这个数据
                }
            }
            for (int start = i; start < sLength - wordLength * wordsCnt + 1 ; start += wordLength) {
                // 这个循环，是从i(start)开始，每次start增加一个单词的长度
                if (start != i) {// 如果 start 的位置不是i的位置，进行下面的操作，也就是第一个除外，其他情况如下
                    // 获取，一个字符串从s中获取，位置从，start开始计算，获取倒数最后一个字符串单词
                    //
                    string word = s.substr(start + (wordsCnt - 1) * wordLength , wordLength);
                    if ( ++ differ[word] == 0) { // 如果这个单词在hash表中的情况在 ++ 后为1，那么删除
                        differ.erase(word);
                    }
                    word = s.substr(start - wordLength,wordLength); // 查看前面一个字符串
                    if (-- differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) { // 如果此时为0，那么这个时候的start的位置就是串联字符串的起始位置
                    answer.emplace_back(start);
                }
            }
        }
        return answer;
    }
    /**
     * 32 最长有效括号
     * @param s
     * @return
     */
    int longestValidParentheses_1(string s) {
        int maxNs = 0, n = s.length();
        // 1. 动态规划
        vector <int> dp(n,0); // 设置n个vector，每个容器初始值为0
        for (int i = 1 ; i < n ; i ++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = ( i >= 2? dp [i-2] : 0 ) + 2;
                } else if (i - dp [i-1] > 0 && s[i-dp[i-1]-1] == '(' ) {
                    dp [i] = dp[i-1] + ((i-dp[i-1]) >= 2 ? dp[i-dp[i-1]-2]:0) + 2;
                }
                maxNs = max(maxNs, dp[i]);
            }
        }
        // 2， 栈
        // 3. 顺序访问字符串
        return maxNs;
    }
    int longestValidParentheses_2(string s) {
        int maxNs = 0, sLength = s.length();
        // 1. 动态规划
        // 2， 栈
        // 3. 顺序访问字符串
        int lLeft = 0 , lRight = 0;
        int rLeft = 0 , rRight = 0;
        for (int i = 0 ; i < sLength ; i ++ ) {
            if (s[i] == '(') {
                lLeft ++;
            } else {
                lRight++;
            }
            if ( lRight == lLeft) {
                maxNs = max(maxNs,lRight * 2);
            } else if (lRight > lLeft) {
                lRight = lLeft = 0;
            }
            if (s[sLength - i - 1] == ')') {
                rRight ++;
            } else {
                lLeft ++;
            }
            if (rLeft == rRight) {
                maxNs = max(maxNs,rLeft * 2);
            } else if (rLeft > rRight) {
                rRight = rLeft = 0;
            }
        }

//        for (int i = 0 ; i < sLength ; i++ ){
//            if (s[i] == '(') left ++;
//            else right++;
//            if (left < right) {
//                left = right = 0;
//            } else if (left == right){
//                maxNs = max(maxNs,right * 2);
//            }
//        } for (int i = sLength - 1 ; i >= 0 ; i --) {
//            if (s[i] == ')')right++;
//            else left++;
//            if (left > right) {
//                left = right = 0;
//            } else if (left == right) {
//                maxNs = max(maxNs, left*2);
//            }
//        }
        return maxNs;
    }
    /**
     * 41. 缺失的第一个正数
     * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
     * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
     * 如果所有的正数从1到N的沾满了N个单元，那么最小的未出现的正数为N+1
     * 之后遍历这个修改后的数组，
     * 开始重新遍历，每次当前元素所对应的位置的数据转换为符号，一次根据元素的所有数据转换为绝对值的计算，
     * @param nums
     * @return
     */
    int firstMissingPositive_hash(vector<int>& nums) {
        // 哈希表
        // 先将所有的数字转换为整数，统一为N+1，
        int minNumber;
        int numsSize = nums.size();
        for (int & num : nums) {
            if (num <= 0) num = numsSize + 1;
        }
        for (int i = 0;i < numsSize ;i++) {
            int num = abs(nums[i]);
            if (num <= numsSize) {
                nums[num - 1] = - abs(nums[num-1]);
            }
        }
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] > 0 ) return i+1;
        }
        return numsSize + 1;
    }
    /**
     * 41
     * @param nums
     * @return
     */
    int firstMissingPositive_transmit(vector<int>& nums) {
        // 置换的方法，将所有的数据放置到正确的位置，直到出现第一个位置上错的数据，或者达到最后的位置
        int numsSize = nums.size();
        for (int i = 0 ; i < numsSize ; i++) {
            while (0 < nums[i] && nums[i] <= numsSize && nums[nums[i]-1] != nums[i]) {
                swap (nums[i],nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < numsSize;i++ ) {
            if (nums[i] != i+1) return i+1;
        }
        return numsSize + 1;
    }
    /**
     * 53 最大子数组和
     * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
     * 子数组是数组中的一个连续部分。
     * 1 <= nums.length <= 10^5
     * -10^4 <= nums[i] <= 10^4
     * @param nums
     * @return
     */
    int maxSubArray(vector<int>& nums) {
        // 动态规划
        int pre = 0, maxAnswer = nums [0] ;
        for (const auto &x : nums) {
            pre = max (pre + x, x); // 记录下挡墙最大的数值
            maxAnswer = max(maxAnswer,pre); // 记录下来当前最大的结果
        }
        return maxAnswer;
    }
};

int main () {
    Solution sol;
    vector<int> nums;
    nums = {1,2};
    sol.maxSubArray(nums);
}