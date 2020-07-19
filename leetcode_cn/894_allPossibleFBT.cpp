/*
满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。

返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。

答案中每个树的每个结点都必须有 node.val=0。

你可以按任何顺序返回树的最终列表。

 

示例：

输入：7
输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

提示：

1 <= N <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-possible-full-binary-trees
*/
// 满二叉树其左右子树也是一颗满二叉树，如此递归
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
    vector<TreeNode*> allPossibleFBT(int N) {
        // 偶数个节点不能组成满二叉树
        if ((N & 1) == 0) {
            return {};
        }
        if (N == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> res;
        for (int i = 1; i < N - 1; ++i) {
            int j = N - 1 - i;
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(j);
            for (auto lt : left) {
                for (auto rt : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
