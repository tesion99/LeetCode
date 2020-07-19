/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
*/
// 与105类似，后续遍历与前序遍历相反
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe) {
        if (ps < 0 || ps >= post.size() || pe < 0 || pe >= post.size() || pe < ps) {
            return nullptr;
        }
        int root_idx = m[post[pe]];
        TreeNode* root = new TreeNode(post[pe]);
        int mid = pe - 1;
        while (mid >= ps && m[post[mid]] > root_idx) {
            --mid;
        }
        TreeNode* left = buildTree(in, is, root_idx - 1, post, ps, mid);
        TreeNode* right = buildTree(in, root_idx + 1, ie, post, mid + 1, pe - 1);
        root->left = left;
        root->right = right;
        return root;
    }
};
