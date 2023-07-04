/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        auto p = head;
        while (p != nullptr) {
            ++length;
            p = p->next;
        }
        int d = length / k, r = length % k;
        vector<ListNode*> res(k, nullptr);
        p = head;
        for (int i = 0; i < k && p != nullptr; ++i) {
            res[i] = p;
            int size = d + (i < r ? 1 : 0);
            for (int j = 1; j < size; ++j)
                p = p->next;
            ListNode* next = p->next;
            p->next = nullptr;
            p = next;
        }
        return res;
    } 
};
// @lc code=end

