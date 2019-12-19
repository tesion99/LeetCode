/*
给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
注意：

二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
---------------------
Note: BST的中序遍历为一个升序的数组
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
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        traversal(root, nums);
        int min_diff = INT_MAX;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            if (i > 0) {
                if (nums[i] - nums[i-1] < min_diff) {
                    min_diff = nums[i] - nums[i-1];
                }
            }
        }
        return min_diff;
    }

    void traversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left, nums);
        nums.push_back(root->val);
        traversal(root->right, nums);
    }
};

// 根据BST树后续节点的上下限结点作为递归参数，是下层结点能够获取到上层的限制结点值
// 用于做比较判断
// 此方法参考isValidBST练习题的官方解法
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
    int minDiffInBST(TreeNode* root) {
        int min_diff = INT_MAX;
        helper(root, nullptr, nullptr, min_diff);
        return min_diff;
    }

    void helper(TreeNode* root, TreeNode* pre, TreeNode* last, int& diff) {
        if (root == nullptr) {
            return;
        }
        // pre与last指定上下限结点
        if (pre) {
            diff = min(diff, root->val - pre->val);
        } 

        if (last) {
            diff = min(diff, last->val - root->val);
        }
        helper(root->left, pre, root, diff);
        helper(root->right, root, last, diff);
    }
};
