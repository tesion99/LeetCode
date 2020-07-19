/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
// 利用树中序排序的特点，先取中间的节点为root节点，
// 在对左右部分分别取中间结点，形成left和right
// 递归执行以上操作
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }
        return getRoot(vec, 0, vec.size() - 1);
    }
    TreeNode* getRoot(vector<ListNode*>& vec, int start, int end) {
        if (start < 0 || start >= vec.size() || end < 0 || end >= vec.size() || end < start) {
            return nullptr;
        }
        int cnt = end - start + 1;
        int mid = (end + start) / 2;
        if ((cnt & 1) == 0) {
            ++mid;
        }
        TreeNode* root = new TreeNode(vec[mid]->val);
        root->left = getRoot(vec, start, mid - 1);
        root->right = getRoot(vec, mid + 1, end);
        return root;
    }
};
