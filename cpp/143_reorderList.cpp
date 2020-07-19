/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        stack<ListNode*> st;
        ListNode* p = head;
        while (p) {
            st.push(p);
            p = p->next;
        }
        p = head;
        ListNode* last = head->next;
        while (p) {
            if (st.empty()) {
                break;
            }
            ListNode* q = st.top();
            if (last == q) {
                break;
            }

            p->next = q;
            q->next = last;
            p = last;
            st.pop();
            // 1->2->3这类，避免形成环
            if (last && last->next == q) {
                break;
            }
            last = last ? last->next : nullptr;
        }
        if (!st.empty()) {
            cout << st.top()->val << endl;
            st.top()->next = nullptr;
        }
    }
};
