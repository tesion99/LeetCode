/*
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
*/

// 递归查找，同时在每个结点产生新的搜索路径
// TODO: 以下代码效率较低，加入了set避免重复路径
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
    set<TreeNode*> s;
    int pathSum(TreeNode* root, int sum) {
        if (root) s.insert(root);
        return pathSum(root, sum, sum);
    }

    // target 保存链条所需要的值，sum为原始目标值，当本路径不满足时，产生新路径
    int pathSum(TreeNode* root, int target, int sum) {
        if (root == nullptr) {
            //if (target == 0) return 1;
            return 0;
        }

        int val = (root->val == target) ? 1 : 0;
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        }

        int l = 0;
        if (root->left) {
            l = pathSum(root->left, target - root->val, sum);
            if (s.find(root->left) == s.end()) {
                l += pathSum(root->left, sum);
                s.insert(root->left);
            }
        }
        
        int r = 0;
        if (root->right) {
            r = pathSum(root->right, target - root->val, sum);
            if (s.find(root->right) == s.end()) {
                r += pathSum(root->right, sum);
                s.insert(root->right);
            }
        }

        return val + l + r;
    }
};
