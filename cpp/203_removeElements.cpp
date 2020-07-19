/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        ListNode* cur = nullptr;
        while (head) {
            cur = head;
            head = head->next;
            if (cur->val == val) {
                delete cur;
            } else {
                cur->next = nullptr;
                pre->next = cur;
                pre = cur;
            }
        }
        return dummy.next;
    }
};
