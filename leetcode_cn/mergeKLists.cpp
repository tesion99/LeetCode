/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(INT_MIN);
        size_t sz = lists.size();
        ListNode* pcur = &head;
        size_t idx = sz;

        while (idx) {
            for (int i = 0; i < sz; ++i) {
                if (!lists[i]) continue;

                if (idx == sz) {
                    idx = i;
                    continue;
                }

                if (lists[idx]->val > lists[i]->val) {
                    idx = i;
                }
            }

            if (idx == sz) break;

            pcur->next = lists[idx];
            pcur = lists[idx];
            lists[idx] = lists[idx]->next;
            pcur->next = nullptr;

            idx = sz;
        }

        return head.next;
    }
};
