/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (55.66%)
 * Likes:    1581
 * Dislikes: 0
 * Total Accepted:    406.8K
 * Total Submissions: 730.6K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right)
            return head;
        int cur = 1;
        ListNode *begin = nullptr, *now = head;
        while (cur < left && now != nullptr) {
            begin = now;
            now = now->next;
            ++cur;
        }
        auto end = now;
        ListNode *next = now->next, *pre = nullptr; 
        while (next != nullptr && cur < right) {
            now->next = pre;
            pre = now;
            now = next;
            next = next->next;
            ++cur;
        }
        now->next = pre;
        if (begin != nullptr)
            begin->next = now;
        else {
            end->next = next;
            return now;
        }
        end->next = next;
        return head;
    }
};
// @lc code=end

