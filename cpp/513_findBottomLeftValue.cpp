/*
给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 

注意: 您可以假设树（即给定的根节点）不为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
*/
// 1. 借助queue做层序遍历，取每层最左边的一个，空间复杂度: O(n)，时间复杂度: O(n)
// 2. 使用变量记录当前所在层cur_level，当后续遍历的层次level > cur_level，表明到达新层，更新结果与当前层
// 3. 进行后续遍历，先遍历左子树，在遍历右子树
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
    int cur_level = -1;
    int res = 0;

    int findBottomLeftValue(TreeNode* root) {
        findLeftValue(root, 0);
        return res;
    }
    void findLeftValue(TreeNode* root, int level) {
        if (!root) {
            return;
        }
        
        if (level > cur_level) {
            res = root->val;
            cur_level = level;
        }
        findLeftValue(root->left, level + 1);
        findLeftValue(root->right, level + 1);
    }
};
