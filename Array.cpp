//
// Created by Administrator on 2024/3/7.
//
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    /*
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
};