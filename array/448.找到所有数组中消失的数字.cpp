/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (65.89%)
 * Likes:    1234
 * Dislikes: 0
 * Total Accepted:    281.3K
 * Total Submissions: 426.9K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums
 * 中的数字，并以数组的形式返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1]
 * 输出：[2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * 1 
 * 
 * 
 * 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。
 * 
 */
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (auto x: nums) {
            nums[abs(x) - 1] = -abs(nums[abs(x) - 1]);
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};
// @lc code=end
