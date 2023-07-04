/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto dummy = new ListNode(-101, head);
        auto pre = dummy, p = head, q = head->next;
        while (q != nullptr) {
            if (p->val == q->val) {
                while (q != nullptr && p->val == q->val) {
                    auto t = q;
                    q = q->next;
                    delete t;
                }
                pre->next = q;
                delete p;
                p = q;
                if (q != nullptr)
                    q = q->next;
            } else {
                pre = p;
                p = p->next;
                q = q->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

