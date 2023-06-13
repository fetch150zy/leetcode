/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode.cn/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (59.35%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    91.1K
 * Total Submissions: 153.6K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2,3,1]
 * 输出：2
 * 解释：
 * 输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
 * 连续子数组里面拥有相同度的有如下所示：
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,2,3,1,4,2]
 * 输出：6
 * 解释：
 * 数组的度是 3 ，因为元素 2 重复出现 3 次。
 * 所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums.length 在 1 到 50,000 范围内。
 * nums[i] 是一个在 0 到 49,999 范围内的整数。
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> bucket;
        for (int i = 0; i < n; ++i) {
            if (bucket.count(nums[i])) {
                ++bucket[nums[i]][0];
                bucket[nums[i]][2] = i;
            } else {
                bucket[nums[i]] = {1, i, i};
            }
        }
        int res = 1, val = -1;

        for (auto& [_, item]: bucket) {
            if (val < item[0]) {
                val = item[0];
                res = item[2] - item[1] + 1;
            } else if (val == item[0]) {
                if (res > item[2] - item[1] + 1)
                    res = item[2] - item[1] + 1;
            }
        }
        return res;
    }
};
// @lc code=end

