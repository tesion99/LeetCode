/*
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？
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
    bool hasCycle(ListNode *head) {
        set<ListNode *> pset;

        while (head) {
            auto res = pset.insert(head);
            if (!res.second) return true;

            head = head->next;
        }

        return false;
    }
};

/*
 * 通过每次从head开始遍历查找，来比对与cur节点的下一个节点是否一致
 * 实现空间复杂度O(1)
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
    bool hasCycle(ListNode *head) {
        if (nullptr == head) return false;

        if (head == head->next) return true;

        ListNode * cur = head->next;
        ListNode * q = nullptr;


        while (cur) {
            q = head;
            while (q->next != cur) {
                if (q->next == cur->next) return true;

                q = q->next;
            }

            if (cur == cur->next) return true;

            cur = cur->next;
        }

        return false;
    }
};

/*
 * 官方参考: 使用快慢指针，如相遇，则说明有环路
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode * slow = head;
        ListNode * fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};
