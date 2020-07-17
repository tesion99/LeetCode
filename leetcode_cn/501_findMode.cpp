/*
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
*/
// 中序遍历，将结果集res当做临时栈，
// 当有次数相同的值出现时，值入栈；
// 当值出现次数大于栈中元素出现次数时，清空栈，新值入栈
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
    int cnt = 0, cur = 0;
    int pre_cnt = 0;
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        // 中序遍历，将res当做栈来使用，弹出出现次数少的值，压入出现次数多的值
        inorderTraversal(root, res);
        // 判断最后相等区域
        if (cnt > pre_cnt) {
            res.clear();
            res.push_back(cur);
        } else if (cnt == pre_cnt) {
            if (cnt != 0) {
                res.push_back(cur);
            }
        }

        return res;
    }

    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if (!root) return;

        inorderTraversal(root->left, res);
        int val = root->val;
        if (cnt == 0) {
            cur = val;
            cnt = 1;
        } else {
            if (cur == val) {
                ++cnt;
            } else {
                // 根据BST中序遍历为有序的特征，当遇到第一个值不相等的点时，开始新区间
                if (pre_cnt == cnt) {
                    // 出现次数相同，直接保存数据
                    res.push_back(cur);
                } else if (pre_cnt < cnt) {
                    res.clear();
                    res.push_back(cur);
                    pre_cnt = cnt;
                }
                cnt = 1;
                cur = val;
            }
        }
        inorderTraversal(root->right, res);
    }
};
