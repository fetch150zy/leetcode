/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 *
 * https://leetcode.cn/problems/1-bit-and-2-bit-characters/description/
 *
 * algorithms
 * Easy (55.27%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    68.7K
 * Total Submissions: 124.3K
 * Testcase Example:  '[1,0,0]'
 *
 * 有两种特殊字符：
 * 
 * 
 * 第一种字符可以用一比特 0 表示
 * 第二种字符可以用两比特（10 或 11）表示
 * 
 * 
 * 给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: bits = [1, 0, 0]
 * 输出: true
 * 解释: 唯一的解码方式是将其解析为一个两比特字符和一个一比特字符。
 * 所以最后一个字符是一比特字符。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：bits = [1,1,1,0]
 * 输出：false
 * 解释：唯一的解码方式是将其解析为两比特字符和两比特字符。
 * 所以最后一个字符不是一比特字符。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= bits.length <= 1000
 * bits[i] 为 0 或 1
 * 
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n - 1)
            i += bits[i] + 1;
        return i == n - 1;
    }
};
// @lc code=end

