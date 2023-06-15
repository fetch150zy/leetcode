/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 *
 * https://leetcode.cn/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (65.01%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    73.6K
 * Total Submissions: 113.2K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * 请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 * 
 * 
 * 
 * 举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。
 * 
 * 如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
 * 
 * 如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root1 = [1,2,3], root2 = [1,3,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的两棵树结点数在 [1, 200] 范围内
 * 给定的两棵树上的值在 [0, 200] 范围内
 * 
 * 
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
// Definition for a binary tree node.
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
    void find_leaf(TreeNode* root, bool flag) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            if (flag)
                leaf1.push_back(root->val);
            else
                leaf2.push_back(root->val);
            return;
        }
        find_leaf(root->left, flag);
        find_leaf(root->right, flag);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        find_leaf(root1, true);
        find_leaf(root2, false);

        return (leaf1.size() == leaf2.size() && equal(leaf1.begin(), leaf1.end(), leaf2.begin()));
    }
private:
    vector<int> leaf1;
    vector<int> leaf2;
};
// @lc code=end

