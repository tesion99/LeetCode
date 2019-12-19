/*
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-univalue-path
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
    int longestUnivaluePath(TreeNode* root) {
        int val = 0;
        helper(root, val);
        return val;
    }

    int helper(TreeNode* root, int& val) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }

        int left_long = helper(root->left, val);
        int right_long = helper(root->right, val);
        int l = 0, r = 0;

        if(root->left && root->val == root->left->val) {
            l = left_long + 1;
        }
        if (root->right && root->val == root->right->val) {
            r = right_long + 1;
        }

        val = max(val, l + r);
        // 每次返回最近一直复合条件的路径数
        return max(l, r);
    }
};
