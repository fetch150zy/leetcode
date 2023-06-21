/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 *
 * https://leetcode.cn/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (77.18%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    79.2K
 * Total Submissions: 102.6K
 * Testcase Example:  '1\n22'
 *
 * 自除数 是指可以被它包含的每一位数整除的数。
 * 
 * 
 * 例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 * 
 * 
 * 自除数 不允许包含 0 。
 * 
 * 给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：left = 1, right = 22
 * 输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：left = 47, right = 85
 * 输出：[48,55,66,77]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= left <= right <= 10^4
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i)
            if (check(i))
                res.push_back(i);
        return res;
    }

    bool check(int x) {
        int y = x;
        while (y > 0) {
            if (y % 10 == 0)
                return false;
            if (x % (y % 10) != 0)
                return false;
            y /= 10;
        }
        return true;
    }
};
// @lc code=end

