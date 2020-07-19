/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
*/
// 从当前结点出发，删除其后续中的重复节点，时间复杂度: O(n^2)
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* p = head;
        while (p) {
            ListNode* q = p->next, * pre = p;
            while (q) {
                if (q->val != p->val) {
                    pre->next = q;
                    pre = q;
                }
                q = q->next;
            }
            pre->next = nullptr;
            p = p->next;
        }
        return head;
    }
};
