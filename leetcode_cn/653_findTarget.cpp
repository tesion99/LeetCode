/*
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
*/
// BST中序遍历 + hash
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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        set<int> s;
        bool res = false;
        inorderTraversal(root, k, s, res);
        return res;
    }
    void inorderTraversal(TreeNode* root, int k, set<int>& s, bool& res) {
        if (res || root == nullptr) {
            return;
        }
        inorderTraversal(root->left, k, s, res);
        if (s.find(root->val) != s.end()) {
            res = true;
            return;
        } else {
            s.insert(k - root->val);
        }
        inorderTraversal(root->right, k, s, res);
    }
};
