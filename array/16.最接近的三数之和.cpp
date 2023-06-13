/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode.cn/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (44.86%)
 * Likes:    1402
 * Dislikes: 0
 * Total Accepted:    470.9K
 * Total Submissions: 1M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 
 * 返回这三个数的和。
 * 
 * 假定每组输入只存在恰好一个解。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 1e5;

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            // 双指针
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                    return target;
                if (abs(sum - target) < abs(res - target))
                    res = sum;
                if (sum > target) {
                    --right;
                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                } else {
                    ++left;
                    while (left < right && nums[left] == nums[left - 1])
                        ++left;
                }
            }
        }
        return res;
    }
};
// @lc code=end

