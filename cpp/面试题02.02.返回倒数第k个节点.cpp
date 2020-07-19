/*
实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。
*/
// 先取出链表长度，再减去倒数的个数，得到从头开始需要移动的次数
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
    int kthToLast(ListNode* head, int k) {
        if (head == nullptr || k <= 0) {
            return 0;
        }
        int len = getLength(head);
        int distance = len - k;
        for (int i = 0; i < distance; ++i) {
            head = head->next;
        }
        return head->val;
    }
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};
