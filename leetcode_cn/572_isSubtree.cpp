/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。

s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
*/
// 先检测root节点值是否相等，如果相同，检测整个root树与目标树t是否相同
// 如果不相同，继续后续左右子树，查找与root节点值相同的点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res = false;
        check(s, t, res);
        return res;
    }
    void check(TreeNode* s, TreeNode* t, bool& res) {
        if (!s && t || s && !t || res == true) {
            return;
        }
        if (s && t && s->val != t->val || !isSameTree(s, t)) {
            check(s->left, t, res);
            check(s->right, t, res);
            return;
        }
        res = true;
    }
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        } else if (!s && t || s && !t) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};
