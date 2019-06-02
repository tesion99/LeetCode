/*
编写一个程序，找到两个单链表相交的起始节点。

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *Ps: 
 *  使用stack，从链表尾部元素开始比对，知道找到第一个不同地址的node即可
 *  该方式空间复杂度为O(n)
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> sa, sb;
        ListNode * pre = nullptr;
        
        while (headA) {
            sa.push(headA);
            headA = headA->next;
        }
        
        while (headB) {
            sb.push(headB);
            headB = headB->next;
        }
        
        while (!sa.empty()) {
            if (sb.empty()) break;
            
            if (sa.top() != sb.top()) {
                break;
            } 
            
            pre = sa.top();
            sa.pop();
            sb.pop();
        }
        
        return pre;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Ps:
 *  考虑到链表长短不一，若调整为相同长度的链表，然后从头开始遍历
 *  当查询到第一个相同的节点时，即可退出
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        ListNode * pre = nullptr, * pa = headA, * pb = headB;

        if (headA == nullptr || headB == nullptr) return pre;

        while (pa) {
            ++lena;
            pa = pa->next;
        }

        while (pb) {
            ++lenb;
            pb = pb->next;
        }

        // 调整两个链表为相同的长度
        while (lena > lenb) {
            headA = headA->next;
            --lena;
        }

        while (lenb > lena) {
            headB = headB->next;
            --lenb;
        }

        // 长度相同的两个链表，从头开始找
        while (headB || headA) {
            if (headA == nullptr || headB == nullptr) break;

            if (headA == headB) {
                pre = headA;
                break;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return pre;
    }
};
