/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

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
  [20,9],
  [15,7]
]
 

提示：

节点总数 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof
*/
// 层序遍历，每一层分别存储
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
        queue<vector<TreeNode*>> q;
        vector<vector<int>> res;
        vector<TreeNode*> nodes;
        if (root) {
            nodes.push_back(root);
            q.push(nodes);
        }
        int level = 0;
        while (!q.empty()) {
            vector<TreeNode*>& ns = q.front();
            int sz = ns.size();
            vector<int> tmp;
            nodes.clear();

            for (int i = 0; i < sz; ++i) {
                int idx = (level & 1) ? sz - 1 - i : i;
                tmp.push_back(ns[idx]->val);
                if (ns[i]->left) {
                    nodes.push_back(ns[i]->left);
                }
                if (ns[i]->right) {
                    nodes.push_back(ns[i]->right);
                }
            }
            q.pop();
            if (!nodes.empty()) {
                q.push(nodes);
            }
            res.push_back(tmp);
            ++level;
        }
        return res;
    }
};
