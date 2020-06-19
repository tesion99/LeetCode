/*
实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。


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
链接：https://leetcode-cn.com/problems/check-balance-lcci
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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode* root, int &depth) {
        if (root == nullptr) {
            depth = 0;
            return true;
        }

        int leftDepth = 0;
        if (!isBalanced(root->left, leftDepth)) {
            return false;
        }
        int rightDepth = 0;
        if (!isBalanced(root->right, rightDepth)) {
            return false;
        }

        if (abs(leftDepth - rightDepth) > 1) {
            return false;
        }

        depth = 1 + max(leftDepth, rightDepth);
        return true;
    }
};
