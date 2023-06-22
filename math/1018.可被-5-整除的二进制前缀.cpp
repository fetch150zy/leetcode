/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 *
 * https://leetcode.cn/problems/binary-prefix-divisible-by-5/description/
 *
 * algorithms
 * Easy (50.62%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    51.1K
 * Total Submissions: 101K
 * Testcase Example:  '[0,1,1]'
 *
 * 给定一个二进制数组 nums ( 索引从0开始 )。
 * 
 * 我们将xi 定义为其二进制表示形式为子数组 nums[0..i] (从最高有效位到最低有效位)。
 * 
 * 
 * 例如，如果 nums =[1,0,1] ，那么 x0 = 1, x1 = 2, 和 x2 = 5。
 * 
 * 
 * 返回布尔值列表 answer，只有当 xi 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [0,1,1]
 * 输出：[true,false,false]
 * 解释：
 * 输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为 true 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,1,1]
 * 输出：[false,false,false]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5^ 
 * nums[i] 仅为 0 或 1
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return {false};
        vector<bool> res;
        vector<int> v(n);
        v[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            int t = (v[i - 1] << 1) % 5;
            v[i] = t + nums[i];
            v[i] %= 5;
        }
        for (auto x: v) {
            if (x == 0)
                res.push_back(true);
            else 
                res.push_back(false);
        }
        return res;
    }
};
// @lc code=end

