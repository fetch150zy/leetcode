/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (51.99%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    118.5K
 * Total Submissions: 227.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：24
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [-1,-2,-3]
 * 输出：-6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 
 * -1000 
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);
    }
};
// @lc code=end

