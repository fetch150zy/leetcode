/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.98%)
 * Likes:    1035
 * Dislikes: 0
 * Total Accepted:    327.9K
 * Total Submissions: 619K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:a = "11", b = "1"
 * 输出："100"
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res = "";
        bool ca = false;
        int m = a.length(), n = b.length();
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (j == n) {
                if (a[i] == '1' && ca) { res += '0'; ca = true; }
                else if (a[i] == '0' && !ca) { res += '0'; ca = false; }
                else { res += '1'; ca = false; }
                ++i;
            } else if (i == m) {
                if (b[j] == '1' && ca) { res += '0'; ca = true; }
                else if (b[j] == '0' && !ca) { res += '0'; ca = false; }
                else { res += '1'; ca = false; }
                ++j;
            } else {
                if (a[i] == '1' && b[j] == '1') {
                    if (ca) res += '1';
                    else res += '0';
                    ca = true;
                } else if (a[i] == '0' && b[j] == '0') {
                    if (ca) res += '1';
                    else res += '0';
                    ca = false;
                } else {
                    if (ca) { res += '0'; ca = true; }
                    else { res += '1'; ca = false; }
                }
                ++i;
                ++j;
            }
        }
        if (ca) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
