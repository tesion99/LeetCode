/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
---------------------
Note: 利用将遍历过的节点的左右孩子标记为null，避免重复遍历，但源树被破坏
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            if (cur->left) {
                st.push(cur->left);
                cur->left = nullptr; // 标记左孩子已被遍历，防止重复
                continue;
            }
            if (cur->right) {
                st.push(cur->right);
                cur->right = nullptr;  // 标记右孩子已被遍历，防止重复
                continue;
            }

            res.push_back(cur->val);
            st.pop();
        }

        return res;
    }
};
