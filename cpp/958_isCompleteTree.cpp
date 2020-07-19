/*
给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

 

示例 1：



输入：[1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
示例 2：



输入：[1,2,3,4,5,null,7]
输出：false
解释：值为 7 的结点没有尽可能靠向左侧。
 

提示：

树中将会有 1 到 100 个结点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree
*/
// 类似层序遍历
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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        // 层序遍历
        vector<TreeNode*> cur, tmp;
        cur.push_back(root);
        int level_cnt = 1;
        bool hasEmptyNode = false;
        bool isLast = false;
        while (!cur.empty()) {
            int sz = cur.size();
            if (!isLast && sz != level_cnt) return false;

            tmp.clear();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = cur[i];
                if (isLast && (node->left || node->right)) {
                    return false;
                }
                if (node->left) {
                    if (hasEmptyNode) return false;
                    tmp.push_back(node->left);
                    if (node->right) {
                        tmp.push_back(node->right);
                    } else {
                        hasEmptyNode = true;
                    }
                } else {
                    hasEmptyNode = true;
                    if (node->right) {
                        return false;
                    }
                }
            } // end for

            if (hasEmptyNode) isLast = true;
            tmp.swap(cur);
            level_cnt *= 2;
        }

        return true;
    }
};
