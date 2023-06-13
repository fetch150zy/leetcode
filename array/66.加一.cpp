/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto n = digits.size();
        vector<int> res(digits);
        res.insert(res.begin(), 0);
        res[n] += 1;
        for (int i = n; i > 0; --i) {
            if (res[i] == 10) {
                res[i] = 0;
                res[i - 1] += 1;
            }
        }
        if (res.front() == 0)
            res.erase(res.begin());
        return res;
    }
};
// @lc code=end

