/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 *
 * https://leetcode.cn/problems/rotate-string/description/
 *
 * algorithms
 * Easy (63.26%)
 * Likes:    285
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 126.4K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * 给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
 * 
 * s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 
 * 
 * 
 * 例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcde", goal = "cdeab"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abcde", goal = "abced"
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, goal.length <= 100
 * s 和 goal 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        string sc = s;
        do {
            sc = sc.substr(1) + sc[0];
            cout << sc << endl;
            if (sc == goal)
                return true;
        } while (sc != s);
        return false;
    }
};
// @lc code=end

