/*
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1);
    }

    TreeNode* bst(vector<int>& nums, int start, int end) {
        if (start < 0 || start >= nums.size()
            || end < 0 || end > nums.size() || start > end) {
            return nullptr;
        }

        int mid = (end + start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums, start, mid - 1);
        root->right = bst(nums, mid + 1, end);
        return root;
    }
};
