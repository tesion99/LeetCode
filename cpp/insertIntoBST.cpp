/*
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
------------------------
Node: 分治法
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        if (root == nullptr) return node;

        insertNode(root, node);
        return root;
    }

    void insertNode(TreeNode *root, TreeNode *node) {
        if (root == nullptr) return;
        if (root->val <= node->val) {
            if (root->right == nullptr) {
                root->right = node;
                return;
            } else {
                insertNode(root->right, node);
            }
        }

        if (root->val > node->val) {
            if (root->left == nullptr) {
                root->left = node;
            } else {
                insertNode(root->left, node);
            }
        }
    }
};
