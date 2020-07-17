/*
检查子树。你有两棵非常大的二叉树：T1，有几万个节点；T2，有几万个节点。设计一个算法，判断 T2 是否为 T1 的子树。

如果 T1 有这么一个节点 n，其子树与 T2 一模一样，则 T2 为 T1 的子树，也就是说，从节点 n 处把树砍断，得到的树与 T2 完全相同。

示例1:

 输入：t1 = [1, 2, 3], t2 = [2]
 输出：true
示例2:

 输入：t1 = [1, null, 2, 4], t2 = [3, 2]
 输出：false
提示：

树的节点数目范围为[0, 20000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-subtree-lcci
*/
// 先检查到t2的可能头结点，然后从该头结点递归检测是否为同一颗树
// 双递归
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
    bool res = false;

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        check(t1, t2);
        return res;
    }
    void check(TreeNode* t1, TreeNode* t2) {
        if (res) return;

        if (!t1 && !t2) {
            res = true;
            return;
        }

        if (!t1 && t2) return;

        if (t1 && t2 && t1->val == t2->val) {
            res = isSameTree(t1, t2);
        }

        check(t1->left, t2);
        check(t1->right, t2);
    }
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;

        if (!t1 && t2 || t1 && !t2 || t1->val != t2->val) {
            return false;
        }
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
};
