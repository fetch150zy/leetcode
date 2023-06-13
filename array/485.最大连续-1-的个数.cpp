/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 *
 * https://leetcode.cn/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (61.10%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    202.1K
 * Total Submissions: 330.7K
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * 给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,0,1,1,1]
 * 输出：3
 * 解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [1,0,1,1,0,1]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] 不是 0 就是 1.
 * 
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = nums[0], cnt = nums[0];
        nums.push_back(0);
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == 1)
                ++cnt;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }

        return res;
    }
};
// @lc code=end
