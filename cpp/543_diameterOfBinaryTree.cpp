/*
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
*/
// 比对左右子树的直径与当前结点左右子树深度和的大小
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int left_dep = depth(root->left);
        int right_dep = depth(root->right);
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        return max(left_dep + right_dep, max(ld, rd));
    }

    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
};


// 优化，较少depth递归重复求值调用导致效率较低的情况
// 在下层递归时，携带depth返回给上层
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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        return diameterOfBinaryTree(root, depth);
    }

    int diameterOfBinaryTree(TreeNode* root, int& depth) {
        if (root == nullptr) {
            depth = 0;
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            depth = 1;
            return 0;
        }

        int left_depth = 0, right_depth = 0;
        int ld = diameterOfBinaryTree(root->left, left_depth);
        int rd = diameterOfBinaryTree(root->right, right_depth);
        depth = 1 + max(left_depth, right_depth);
        return max(left_depth + right_depth, max(ld, rd));
    }
};
