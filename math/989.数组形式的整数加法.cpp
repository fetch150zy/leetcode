/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 *
 * https://leetcode.cn/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (46.03%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    71.6K
 * Total Submissions: 155.7K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * 整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。
 * 
 * 
 * 例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
 * 
 * 
 * 给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：num = [1,2,0,0], k = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：num = [2,7,4], k = 181
 * 输出：[4,5,5]
 * 解释：274 + 181 = 455
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：num = [2,1,5], k = 806
 * 输出：[1,0,2,1]
 * 解释：215 + 806 = 1021
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 10^4
 * 0 <= num[i] <= 9
 * num 不包含任何前导零，除了零本身
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size() - 1, ca = 0;
        vector<int> res;
        while (k > 0) {
            int x = n >= 0 ? num[n--] : 0;
            int t = ca + (k % 10) + x;
            if (t >= 10) {
                res.push_back(t % 10);
                ca = t / 10;
            } else {
                res.push_back(t);
                ca = 0;
            }
            k /= 10;
        }
        if (ca != 0 && n == -1) {
            res.push_back(ca);
            reverse(res.begin(), res.end());
            return res;
        }
        while(n >= 0) {
            int t = ca + num[n];
            if (t >= 10) {
                res.push_back(t % 10);
                ca = t / 10;
            } else {
                res.push_back(t);
                ca = 0;
            }
            --n;
        }
        if (ca != 0 && n == -1)
            res.push_back(ca);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

