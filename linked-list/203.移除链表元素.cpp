/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (54.88%)
 * Likes:    1265
 * Dislikes: 0
 * Total Accepted:    574.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [], val = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        auto pre = head, now = head->next;
        while (now != nullptr) {
            if (now->val == val) {
                auto t = now;
                now = now->next;
                pre->next = now;
                delete t;
            } else {
                pre = pre->next;
                now = now->next;
            }
        }
        if (head->val == val)
            head = head->next;

        return head;
    }
};
// @lc code=end

