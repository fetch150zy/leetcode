/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;
        for ( ; i >= 0 && j >= 0; ) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        if (i < 0 && j >= 0)
            for (int ii = 0; ii <= j; ++ii)
                nums1[ii] = nums2[ii];
    }
};
// @lc code=end

