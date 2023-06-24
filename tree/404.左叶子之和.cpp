/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (62.34%)
 * Likes:    617
 * Dislikes: 0
 * Total Accepted:    241.6K
 * Total Submissions: 387.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: root = [3,9,20,null,null,15,7] 
 * 输出: 24 
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: root = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }

    void helper(TreeNode* root, int& sum) {
        if (root == nullptr)
            return;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            sum += root->left->val;
        helper(root->left, sum);
        helper(root->right, sum);
    }
};
// @lc code=end

