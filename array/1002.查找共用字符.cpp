/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 *
 * https://leetcode.cn/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (70.71%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    85.2K
 * Total Submissions: 120.6K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序
 * 返回答案。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 由小写英文字母组成
 * 
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> tmp(n, vector<int>(26));
        vector<string> res;
        
        for (int i = 0; i < n; ++i)
            for (auto ch: words[i])
                ++tmp[i][ch - 'a'];
        
        for (int j = 0; j < 26; ++j) {
            int t = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (tmp[i][j] < t)
                    t = tmp[i][j];
            }
            for (int k = 0; k < t; ++k) {
                string s;
                s += (j + 'a');
                res.push_back(s);
            }
        }
        return res;
    }
};
// @lc code=end

