/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        
        for (int i = 2; i <= numRows; ++i) {
            res[i-1].push_back(1);
            for (int j = 1; j < i - 1; ++j)
                res[i-1].push_back(res[i-2][j-1] + res[i-2][j]);
            res[i-1].push_back(1);
        }
        return res;
    }
};
// @lc code=end
