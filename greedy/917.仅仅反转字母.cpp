/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 *
 * https://leetcode.cn/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (59.38%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    77.5K
 * Total Submissions: 130.5K
 * Testcase Example:  '"ab-cd"'
 *
 * 给你一个字符串 s ，根据下述规则反转字符串：
 * 
 * 
 * 所有非英文字母保留在原有位置。
 * 所有英文字母（小写或大写）位置反转。
 * 
 * 
 * 返回反转后的 s 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示
 * 
 * 
 * 1 <= s.length <= 100
 * s 仅由 ASCII 值在范围 [33, 122] 的字符组成
 * s 不含 '\"' 或 '\\'
 * 
 * 
 */
#include <cctype>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isalpha(s[i]) && i < j)
                ++i;
            while (!isalpha(s[j]) && i < j)
                --j;
            swap(s[i], s[j]);
            ++i, --j;
        }
        return s;
    }
};
// @lc code=end

