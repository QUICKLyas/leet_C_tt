//
// Created by Administrator on 2024/3/7.
//
#include <vector>
#include <climits>

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
};