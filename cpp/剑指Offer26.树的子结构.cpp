/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
*/
// 注意：题目约定空树不是任意一个树的子结构
// 整体类似判断子树问题

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return false;
        if (!A) return false;

        // B是A的子结构，不是子树
        if (A->val == B->val && isSameStructure(A, B)) {
            return true;
        }

        if (isSubStructure(A->left, B)) {
            return true;
        }
        return isSubStructure(A->right, B);
    }

    bool isSameStructure(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;

        if (A->val != B->val) return false;

        return isSameStructure(A->left, B->left) && isSameStructure(A->right, B->right);
    }
};
