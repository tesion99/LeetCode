/*
插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4

来源：力扣（LeetCode）
链接：https://dev.lingkou.xyz/problems/insertion-sort-list
*/
// 借助2个栈存储节点
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy(INT_MIN);
        ListNode* pre = & dummy;
        stack<ListNode*> st, tmp;
        st.push(pre);
        while (head) {
            ListNode* cur = head;
            head = head->next;
            cur->next = nullptr;
            if (cur->val >= pre->val) {
                pre->next = cur;
                pre = cur;
                st.push(cur);
                continue;
            }

            while (!st.empty() && st.top()->val > cur->val) {
                tmp.push(st.top());
                st.pop();
            }
            cur->next = tmp.top();
            st.top()->next = cur;
            st.push(cur);
            while (!tmp.empty()) {
                st.push(tmp.top());
                tmp.pop();
            }
        }
        return dummy.next; 
    }
};
