/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
*/
// 从根节点到叶节点，当前结点参与组成新的整数，value = value * 10 + cur
// 递归其左右子树，携带本次新的值value
// 最后到达叶节点时，返回本路径的数值
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
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode* root, int sum) {
        if (root == nullptr) {
            return sum;
        }
        sum = sum * 10 + root->val;
        if (root->left && !root->right) {
            return sumNumbers(root->left, sum);
        } else if (!root->left && root->right) {
            return sumNumbers(root->right, sum);
        } else if (root->left && root->right) {
            return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
        }
        return sum;
    }
};
