/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。

例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

 

示例：



输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

提示：

树中的结点数介于 1 和 1000 之间。
node.val 为 0 或 1 。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers
*/
// 递归，记录每次路径之前的和
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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        sumRootToLeaf(root, 0, res);
        return res;
    }
    void sumRootToLeaf(TreeNode* root, int tmp, int& res) {
        if (root == nullptr) {
            res += tmp;
            return;
        }

        tmp = tmp * 2 + root->val;
        if (!root->left && !root->right) {
            res += tmp;
            return;
        }
        
        if (root->left) {
            sumRootToLeaf(root->left, tmp, res);
        }
        if (root->right) {
            sumRootToLeaf(root->right, tmp, res);
        }
    }
};
