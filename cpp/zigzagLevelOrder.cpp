/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
----------------------------
Note: 在层次遍历的基础上，加上方向选择标志位，每次遍历完一层，变更方向
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }

        queue<vector<TreeNode*>> levels;
        vector<TreeNode*> level(1, root);
        levels.push(level);
        vector<vector<int>> res;
        bool isFromLeft = true;

        while (!levels.empty()) {
            vector<TreeNode*>& nodes = levels.front();
            if (nodes.empty()) {
                break;
            }

            vector<int> vals(nodes.size(), 0);
            vector<TreeNode*> new_level;
            for (int i = 0, sz = nodes.size(); i < sz; ++i) {
                if (!isFromLeft) {
                    vals[sz - 1 - i] = nodes[i]->val;
                } else {
                    vals[i] = nodes[i]->val;
                }
                if (nodes[i]->left) new_level.push_back(nodes[i]->left);
                if (nodes[i]->right) new_level.push_back(nodes[i]->right);
            }
            res.push_back(vals);
            levels.push(new_level);
            levels.pop();
            isFromLeft = !isFromLeft;
        }

        return res;
    }
};
