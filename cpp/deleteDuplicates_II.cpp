/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy, *cur = head;

        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                int target = cur->val;
                while (cur != nullptr && cur->val == target) {
                    cur = cur->next;
                }
                continue;
            }

            pre->next = cur;
            cur = cur->next;
            pre = pre->next;
        }

        pre->next = cur;
        return dummy->next;
    }
};
