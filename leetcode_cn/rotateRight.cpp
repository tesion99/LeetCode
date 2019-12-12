/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
-------------------------
Note: 通过对链表进行首尾相连，然后在确定新head的位置，简化移动操作
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) {
            return head;
        }

        ListNode* rear = head;
        size_t len = 1;
        while (rear->next) {
            rear = rear->next;
            ++len;
        }

        k %= len;
        if (k == 0) {
            return head;
        }

        rear->next = head;
        len = len - k - 1;
        while (len-- >  0) {
            head = head->next;
        }

        rear = head;
        head = head->next;
        rear->next = nullptr;
        return head;
    }
};
