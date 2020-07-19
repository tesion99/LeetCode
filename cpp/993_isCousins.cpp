/*
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

 

示例 1：


输入：root = [1,2,3,4], x = 4, y = 3
输出：false
示例 2：


输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true
示例 3：



输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false
 

提示：

二叉树的节点数介于 2 到 100 之间。
每个节点的值都是唯一的、范围为 1 到 100 的整数。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cousins-in-binary-tree
*/
// 层序遍历，记录目标值的上一层节点
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == x || root->val == y) {
            return false;
        }

        vector<TreeNode*> pre;
        queue<vector<TreeNode*>> q;
        TreeNode* px = nullptr, * py = nullptr;
        q.push(vector<TreeNode*>(1, root));
        while (!q.empty()) {
            vector<TreeNode*> cur = q.front();
            vector<TreeNode*> next_level;
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i]->val == x) {
                    px = cur[i];
                }
                if (cur[i]->val == y) {
                    py = cur[i];
                }
                if (cur[i]->left) {
                    next_level.push_back(cur[i]->left);
                }
                if (cur[i]->right) {
                    next_level.push_back(cur[i]->right);
                }
            }
            if (px || py) {
                break;
            }
            pre.swap(cur);
            q.pop();
            q.push(next_level);
        }

        if (px && py) {
            for (auto& node : pre) {
                if ((node->left == px && node->right != py) || 
                    (node->right == px && node->left != py)) {
                    return true;
                }
            }
        }
        return false;
    }
};
