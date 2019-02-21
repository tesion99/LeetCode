/*
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * pNode = nullptr;
        ListNode * pHead = nullptr;
        ListNode * tempNode = nullptr;
        int v1 = 0;
        int v2 = 0;
        int res = 0;

        while (l1 || l2) {
            if (nullptr == l1 && nullptr == l2) break;

            v1 = (nullptr == l1) ? 0 : l1->val;
            v2 = (nullptr == l2) ? 0 : l2->val;
            res = v1 + v2 + carry;
            carry = res / 10;
            tempNode = new ListNode(res % 10);

            if (nullptr == pHead) {
                pHead = tempNode;
                pNode = tempNode;
            } else {
                pNode->next = tempNode;
                pNode = tempNode;
            }

            if (l1) l1 = l1->next;

            if (l2) l2 = l2->next;

        }

        if (0 != carry) {
            tempNode = new ListNode(carry);
            if (pHead) {
                pNode->next = tempNode;
            } else {
                pHead = tempNode;
            }
        }

        return pHead;
    }
};
