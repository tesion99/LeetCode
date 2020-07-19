/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
-----------------------------
Note: 使用类似前序遍历方式，生成链表，递归左右子树即可
TODO: 每次迭代需要遍历查找最右边的叶子节点较耗时，可优化
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;

        // 先交换左右
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        flatten(root->left);
        flatten(root->right);

        // 遍历右子树，直到最底层最右的叶子节点
        TreeNode* pre = root, *cur = root->right;
        while (cur) {
            pre = cur;
            cur = cur->right;
        }

        pre->right = root->left;
        root->left = nullptr;
    }
};
