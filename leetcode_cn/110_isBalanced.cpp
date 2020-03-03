/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
*/
// 递归，类似获取树深度的depth函数
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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, &depth);
    }

    bool isBalanced(TreeNode* root, int* depth) {
        if (root == nullptr) {
            *depth = 0;
            return true;
        }

        int l_depth = 0, r_depth = 0;
        if (!isBalanced(root->left, &l_depth)) return false;
        if (!isBalanced(root->right, &r_depth)) return false;

        bool ret = abs(l_depth - r_depth) <= 1;
        *depth = 1 + max(l_depth, r_depth);
        return ret;
    }

};
