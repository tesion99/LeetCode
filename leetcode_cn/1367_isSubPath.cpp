/*
给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。

如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False 。

一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。

 

示例 1：



输入：head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：true
解释：树中蓝色的节点构成了与链表对应的子路径。
示例 2：



输入：head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：true
示例 3：

输入：head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：false
解释：二叉树中不存在一一对应链表的路径。
 

提示：

二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
链表包含的节点数目在 1 到 100 之间。
二叉树包含的节点数目在 1 到 2500 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-in-binary-tree
*/
// 注意: 题目中提到"存在一条一直向下的路径", 表明是从根节点开始向下遍历，不包含left-root-right组成的路径
// 先检测相同的头结点，然后检测路径是否相同
// 若不相同，在从左右子树分别检测头结点
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
    bool res = false;
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (res == true) {
            return true;
        }

        if (!head ) {
            return true;
        }
        if (!root && head) {
            return false;
        } 

        if (root->val == head->val && isSamePath(head, root)) {
            res = true;
            return true;
        }
    
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool isSamePath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        if (!root && head) {
            return false;
        }
        if (root->val != head->val) {
            return false;
        }
        return isSamePath(head->next, root->left) || isSamePath(head->next, root->right);
    }
};
