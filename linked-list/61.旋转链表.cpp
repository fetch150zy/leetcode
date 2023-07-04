/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // get length
        int length = 0;
        auto p = head;
        while (p != nullptr) {
            ++length;
            p = p->next;
        }
        if (length == 0 || length == 1)
            return head;
        k = k % length;
        if (k == 0)
            return head;
        p = head;
        for (int i = 0; i < length - k - 1; ++i) 
            p = p->next;
        auto q = p->next;
        p->next = nullptr;
        p = q;
        while (q->next != nullptr)
            q = q->next;
        q->next = head;
        return p;
    }      
};
// @lc code=end

