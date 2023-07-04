/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int listLen(ListNode* head) {
        int length = 0;
        while(head != nullptr) {
            ++length; 
            head = head->next;
        }
        return length;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, 0, listLen(head));
    }

    TreeNode* helper(ListNode*& node, int l, int r) {
        if (l >= r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode();
        root->left = helper(node, l, m);
        root->val = node->val; node = node->next;
        root->right = helper(node, m + 1, r);
        return root;
    }
};
// @lc code=end

