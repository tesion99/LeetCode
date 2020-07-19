/*
 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
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
    ListNode* sortList(ListNode* head) {
        // 模拟插入排序
        ListNode * first = nullptr;
        ListNode * next = nullptr, * pre = nullptr;

        while (head) {
                next = first;
                pre = nullptr;
                while (next) {
                    if (next->val > head->val) break;

                    pre = next;
                    next = next->next;
                }

            if (pre == nullptr) {
                first = head;
                head = head->next;
                first->next = next;
            } else {
                pre->next = head;
                head = head->next;
                pre->next->next = next;
            }
        }

        return first;
    }
};
