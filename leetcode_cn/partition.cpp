/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
--------------------------
Note: 构造额外的两条链，分别放置大于目标数与小于目标数的节点，最后在合并链表
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return head;
        }

        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *front = dummy2, *cur = head, *pre = dummy1;
        while (cur) {
            if (cur->val < x) {
                pre->next = cur;
                pre = cur;
            } else {
                front->next = cur;
                front = cur;
            }
            cur = cur->next;
        }
        front->next = nullptr;
        pre->next = dummy2->next;
        return dummy1->next;
    }
};
