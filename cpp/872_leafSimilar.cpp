/*
请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

 

提示：

给定的两颗树可能会有 1 到 200 个结点。
给定的两颗树上的值介于 0 到 200 之间。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/leaf-similar-trees
*/
// 从左到右，搜集每个树的叶节点值，比对每个值是否相同
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> data1, data2;
        getLeafValue(root1, data1);
        getLeafValue(root2, data2);
        if (data1.size() != data2.size()) {
            return false;
        }

        for (int i = 0; i < data1.size(); ++i) {
            if (data1[i] != data2[i]) {
                return false;
            }
        }
        return true;
    }

    void getLeafValue(TreeNode* root, vector<int>& data) {
        if (root == nullptr) return;
        if (!root->left && !root->right) {
            data.push_back(root->val);
            return;
        }
        getLeafValue(root->left, data);
        getLeafValue(root->right, data);
    }
};
