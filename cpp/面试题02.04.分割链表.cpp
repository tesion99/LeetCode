/*
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。

如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。

分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

示例:

输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8
*/
// 与快排数组的partition类似
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
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        int left = 0, right = vec.size() - 1;
        while (left < right) {
            while (left < right && vec[left]->val < x) {
                ++left;
            }
            while (left < right && vec[right]->val >= x) {
                --right;
            }
            if (right > left) {
                int tmp = vec[left]->val;
                vec[left]->val = vec[right]->val;
                vec[right]->val = tmp;
            }
        }
        return vec.empty() ? nullptr : vec[0];
    }
};
