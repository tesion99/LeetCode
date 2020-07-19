/*
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。

它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
*/
// 若要修改原链表，可以翻转链表，再求和
// 否则借助stack的FILO特性求和
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* pre = nullptr;
        int carry = 0;
        while (!st1.empty() || !st2.empty()) {
            if (st1.empty() && st2.empty()) break;

            int val1 = st1.empty() ? 0 : st1.top();
            int val2 = st2.empty() ? 0 : st2.top();
            int tmp = val1 + val2 + carry;
            carry = tmp / 10;
            ListNode* cur = new ListNode(tmp % 10);
            cur->next = pre;
            pre = cur;
            if (!st1.empty()) {
                st1.pop();
            }
            if (!st2.empty()) {
                st2.pop();
            }
        }

        if (carry != 0) {
            ListNode* cur = new ListNode(carry);
            cur->next = pre;
            pre = cur;
        }
        return pre;
    }
};
