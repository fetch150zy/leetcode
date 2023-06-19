/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode.cn/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (35.37%)
 * Likes:    3847
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 3.4M
 * Testcase Example:  '123'
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 123
 * 输出：321
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = -123
 * 输出：-321
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 120
 * 输出：21
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：x = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        stack<int> v;
        bool flag;
        if (x >= 0) {
            flag = true;
        } else {
            if (x == INT_MIN)
                return 0;
            flag = false;
            x = -x;
        }
        while (x > 0) {
            v.push(x % 10);
            x /= 10;
        }
        long res = 0, k = 1;
        while (!v.empty()) {
            res += v.top() * k;
            v.pop();
            k *= 10;
        }
        if (!flag)
            res = -res;
        return (res > INT_MAX || res < INT_MIN) ? 0 : static_cast<int>(res);
    }
};
// @lc code=end

