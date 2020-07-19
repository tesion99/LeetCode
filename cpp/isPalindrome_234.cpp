/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
*/
// 首先获取list长度
// 找到中间结点，将list分为前后两部分
// 翻转后部分链表
// 比对前部分链表与翻转后的链表是否相同
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // 计算链表长度，查找到rear结点
        ListNode* node = head;
        int len = 0;
        while (node) {
            ++len;
            if (node->next == nullptr) break;

            node = node->next;
        }
        // 先走到对称中间结点处
        ListNode* p = head;
        int step = (len % 2 == 0) ? len / 2 : len / 2 + 1;
        while (step-- > 0) {
            node = p;
            p = p->next;
        }
        // 翻转链表
        node->next = nullptr;
        p = revertList(p);
        ListNode* q = head;
        step = len / 2;
        while (step--) {
            if (p == nullptr) return false;
            if (p->val != q->val) return false;

            p = p->next;
            q = q->next;
        }
        return true;
    }
    ListNode *revertList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *cur = head, *last = cur->next, *pre = nullptr;
        while (cur) {
            cur->next = pre;
            pre = cur;
            cur = last;
            last = cur ? cur->next : nullptr;
        }
        return pre;
    }
};
