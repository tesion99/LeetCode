/*
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        int l = 0, r = 0;
        if (root->left) {
            if (root->left->left == nullptr && root->left->right == nullptr) {
                l = root->left->val;
            } else {
                l = sumOfLeftLeaves(root->left);
            }
        }

        if (root->right) {
            r = sumOfLeftLeaves(root->right);
        }

        return  l + r;
    }
};
