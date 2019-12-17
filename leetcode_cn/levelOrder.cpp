/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
---------------------------
Note:
    层次遍历需要用到queue，但同时需要将每一层的值保存在一个vector中，故需要在queue中区分不同层的节点
    这里考虑使用在queue中每个元素为一个vector，用于存放不同层的节点，从而实现数据遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<vector<TreeNode*>> levels;
        vector<TreeNode*> level(1, root);
        levels.push(level);
        vector<vector<int>> res;

        while (!levels.empty()) {
            vector<TreeNode*>& nodes = levels.front();
            if (nodes.empty()) {
                break;
            }
            vector<int> level_vals;
            vector<TreeNode*> new_level;
            for (int i = 0, sz = nodes.size(); i < sz; ++i) {
                level_vals.push_back(nodes[i]->val);
                if (nodes[i]->left) {
                    new_level.push_back(nodes[i]->left);
                }
                if (nodes[i]->right) {
                    new_level.push_back(nodes[i]->right);
                }
            }

            res.push_back(level_vals);
            levels.push(new_level);
            levels.pop();
        }

        return res;
    }
};
