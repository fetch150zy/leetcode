/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 *
 * https://leetcode.cn/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.44%)
 * Likes:    1358
 * Dislikes: 0
 * Total Accepted:    747.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 4
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int n) {
        if (n == 0)
            return 0;
        double x0, x1;
        x0 = n / 2.0;
        x1 = x0 - (x0 * x0 - n) / (2 * x0); 
        while(abs(x0-x1)>=1e-9)
        {
            x0 = x1;
            x1 = x0 - (x0 * x0 - n) / (2 * x0);
        }
        return x1;
    }
};
// @lc code=end
