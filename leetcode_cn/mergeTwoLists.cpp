/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * pHead = nullptr, * curNode = nullptr, * pNode = nullptr;

        while (l1 || l2) {
            if (nullptr == l1) {
                if (!pHead) {
                    return l2;
                } else {
                    curNode->next = l2;
                    break;
                }

            } else if (nullptr == l2) {
                if (!pHead) {
                    return l1;
                } else {
                    curNode->next = l1;
                    break;
                }
            }

            if (l1->val <= l2->val) {
                pNode = l1;
                l1 = l1->next;
            } else {
                pNode = l2;
                l2 = l2->next;
            }

            pNode->next = nullptr;
            if (nullptr == pHead) {
                pHead = pNode;
                curNode = pNode;
            } else {
                curNode->next = pNode;
                curNode = pNode;
            }
        }

        return pHead;
    }
};

/**
 * 通过收到构造一个head，避免了while循环中的多次head==nullptr的检测，
 * 从而提高运行速度，使代码更为简洁、优雅
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * dummyHead = new ListNode(0);
        ListNode * curNode = dummyHead;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curNode->next = l1;
                curNode = l1;
                l1 = l1->next;
            } else {
                curNode->next = l2;
                curNode = l2;
                l2 = l2->next;
            }
        }

        if (nullptr == l1) curNode->next = l2;

        if (nullptr == l2) curNode->next = l1;

        curNode = dummyHead->next;
        delete dummyHead;
        return curNode;
    }
};
