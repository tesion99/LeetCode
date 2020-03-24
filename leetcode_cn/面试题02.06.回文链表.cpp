/*
编写一个函数，检查输入的链表是否是回文的。

 

示例 1：

输入： 1->2
输出： false 
示例 2：

输入： 1->2->2->1
输出： true 
 

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // 获取长度，查找回文中间对称点
        int len = getLength(head);
        int mid = len / 2;
        if (len & 1) {
            ++mid;
        }
        // 移动至对称中间点
        ListNode* p = head;
        for (int i = 1; i < mid; ++i) {
            p = p->next;
        }
        // 反转后半部分链表
        ListNode* q = revertList(p->next);
        p = head;
        // 将后半部分反转链表与当前链表前半部分比较
        while (q) {
            if (q->val != p->val) {
                return false;
            }
            q = q->next;
            p = p->next;
        }
        return true;
    }
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    ListNode* revertList(ListNode* head) {
        ListNode* pre = nullptr, * cur = head;
        ListNode*last = head ? head->next : nullptr;
        while (cur) {
            cur->next = pre;
            pre = cur;
            cur = last;
            last = cur ? cur->next : nullptr;
        }
        return pre;
    }
};
