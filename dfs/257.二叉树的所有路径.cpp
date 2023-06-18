/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.70%)
 * Likes:    970
 * Dislikes: 0
 * Total Accepted:    317.5K
 * Total Submissions: 449.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            res.push_back(to_string(root->val));
        else {
            helper(root->left, to_string(root->val));
            helper(root->right, to_string(root->val));
        }
        return res;
    }

    void helper(TreeNode* root, string s) {
        if (root == nullptr) {
            return;
        }
        s += "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(s);
        } else {
            if (root->left == nullptr)
                helper(root->right, s);
            else if (root->right == nullptr)
                helper(root->left, s);
            else {
                helper(root->left, s);
                helper(root->right, s);
            }
        }
    }
};
// @lc code=end

