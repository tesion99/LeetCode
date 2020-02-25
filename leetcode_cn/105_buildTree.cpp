/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 

限制：

0 <= 节点个数 <= 5000



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
*/
// 从前序遍历确定root根节点
// 从中序遍历中，找出root节点的索引root_idx
// 前序遍历中的元素在中序中的索引，大于root节点的，属于左子树，否则属于右子树
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
    map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& pre, int ps, int pe, vector<int>& in, int ip, int ie) {
        if (ps < 0 || pe < 0 || ps >= pre.size() || pe >= pre.size() || ps > pe) {
            return nullptr;
        }
        if (ps == pe) {
            return new TreeNode(pre[ps]);
        }
        TreeNode* root = new TreeNode(pre[ps]);
        int root_idx = m[root->val];
        int i = ps + 1;
        for (; i <= pe; ++i) {
            if (m[pre[i]] > root_idx) {
                break;
            }
        }

        TreeNode* left = buildTree(pre, ps + 1, i - 1, in, ip, root_idx - 1);
        TreeNode* right = buildTree(pre, i, pe, in, root_idx + 1, ie);
        root->left = left;
        root->right = right;
        return root;
    }
};
