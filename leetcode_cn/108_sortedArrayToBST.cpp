/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
// 与109类似，提取mid节点作为根节点，在找出左右部分的根节点，递归下去
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getRoot(nums, 0, nums.size() - 1);
    }
    TreeNode* getRoot(vector<int>& vec, int start, int end) {
        if (start < 0 || start >= vec.size() || end < 0 || end >= vec.size() || start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        // 偶数个节点时，取后面一个作为root节点
        if (((end - start + 1) & 1) == 0) {
            ++mid;
        }
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = getRoot(vec, start, mid - 1);
        root->right = getRoot(vec, mid + 1, end);
        return root;
    }
};
