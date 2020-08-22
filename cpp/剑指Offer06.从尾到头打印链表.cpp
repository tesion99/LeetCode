/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/
// 借助栈或者递归，时后来的节点值先进入结果集
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        reverse(head, res);
        return res;
    }

    void reverse(ListNode* head, vector<int>& res) {
        if (head == nullptr) return;
        reverse(head->next, res);
        res.push_back(head->val);
    }
};
