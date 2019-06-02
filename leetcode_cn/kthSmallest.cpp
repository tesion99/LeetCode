/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1

Ps: BST的中序遍历的第k个数即为第k小
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
    int kthSmallest(TreeNode* root, int k) {
        int lnodes = getNodeNum(root->left);

        if (lnodes == k - 1) return root->val;

        if (lnodes > k - 1) {
            return kthSmallest(root->left, k);
        }

        return kthSmallest(root->right, k - 1 - lnodes);
    }

    int getNodeNum(TreeNode * root) {
        if (!root) return 0;

        return 1 + getNodeNum(root->left) + getNodeNum(root->right);
    }
};
