/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

 

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

提示：

0 <= n <= 8


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
*/
// 首先选取 i 作为根节点，递归得到可能的左子树所有根节点left_nodes = generateTrees(1, i - 1)， right_nodes = generateTrees(i + 1, n)
// 如此组成的以 i 为根的节点有left_nodes.size() * right_nodes.size()个
// 递归取i 为 1, ..., n, 即求得所有的root节点数组
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start <= 0 || end <= 0 || start > end) return {};
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left_nodes = generateTrees(start, i - 1);
            vector<TreeNode*> right_nodes = generateTrees(i + 1, end);
            size_t lsize = left_nodes.size();
            size_t rsize = right_nodes.size();
            if (lsize == 0 && rsize == 0) {
                res.push_back(new TreeNode(i));
                continue;
            } else if (lsize != 0 && rsize == 0) {
                for (int n = 0; n < lsize; ++n) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_nodes[n];
                    res.push_back(root);
                }
            } else if (lsize == 0 && rsize != 0) {
                for (int n = 0; n < rsize; ++n) {
                    TreeNode* root = new TreeNode(i);
                    root->right = right_nodes[n];
                    res.push_back(root);
                }
            } else {
                for (int l = 0; l < lsize; ++l) {
                    for (int r = 0; r < rsize; ++r) {
                        TreeNode* root = new TreeNode(i, left_nodes[l], right_nodes[r]);
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
