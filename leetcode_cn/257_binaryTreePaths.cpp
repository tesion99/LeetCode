/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
*/
// 递归
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        backtrace(root, "", res);
        return res;
    }
    void backtrace(TreeNode* root, string path, vector<string>& res) {
        if (root == nullptr) {
            return;
        }
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }

        if (root->left) {
            backtrace(root->left, path, res);
        }

        if (root->right) {
            backtrace(root->right, path, res);
        }
    }
};
