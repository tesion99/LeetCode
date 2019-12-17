/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
----------------------------
Note: 根节点只大于所有左子树的值，小于所有右子树的值
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        bool check = isLess(root->left, root->val) && isGreater(root->right, root->val);

        return check && isValidBST(root->left) && isValidBST(root->right);
    }

    bool isLess(TreeNode* root, int val) {
        if (root == nullptr) return true;

        return root->val < val
               && isLess(root->left, val)
               && isLess(root->right, val);
    }

    bool isGreater(TreeNode* root, int val) {
        if (root == nullptr) return true;

        return root->val > val
               && isGreater(root->left, val)
               && isGreater(root->right, val);
    }
};

// 根据定义，先判断左右子树是否为BST，然后在看root节点与左右子树合起来，是否组成BST
// 这样减少check的次数，尽早使程序返回
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        bool flag = isValidBST(root->left) && isValidBST(root->right);

        if (!flag) return false;

        bool check = isLess(root->left, root->val) && isGreater(root->right, root->val);
        return check;
    }

    bool isLess(TreeNode* root, int val) {
        if (root == nullptr) return true;

        return root->val < val 
               && isLess(root->left, val) 
               && isLess(root->right, val);
    }

    bool isGreater(TreeNode* root, int val) {
        if (root == nullptr) return true;

        return root->val > val
               && isGreater(root->left, val)
               && isGreater(root->right, val);
    }
};
