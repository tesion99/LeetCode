/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
----------------------------
Note: 链表合理利用辅助的哑结点，以简化部分操作复杂度
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* rear = dummy;
        ListNode* p = head;
        while (p && p->next) {
            rear->next = p->next;
            p->next = p->next->next;
            rear->next->next = p;
            p = p->next;
            rear = rear->next->next;
        }

        if (p != nullptr && p->next == nullptr) {
            rear->next = p;
            rear = rear->next;
        }

        rear->next = nullptr;
        return dummy->next;
    }
};
