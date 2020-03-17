/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，

使得每个节点的值是原来的节点值加上所有大于它的节点值之和。 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
 

注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
*/
// 递归，中序遍历，前序和
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
    TreeNode* convertBST(TreeNode* root) {
        int pre_sum = 0;
        dfs(root, pre_sum);
        return root;
    }

    void dfs(TreeNode* root, int& pre_sum) {
        if (root == nullptr) {
            return;
        }
        dfs(root->right, pre_sum);
        root->val += pre_sum;
        pre_sum = root->val;
        dfs(root->left, pre_sum);
    }
};
