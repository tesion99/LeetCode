/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
*/
// 利用递归求解，先确定层数，生成对应的vector，遍历时携带层数，将对应数据放到对应层的vector中
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        int dep = depth(root);
        res.resize(dep);
        traversal(root, 0, dep, res);
        return res;
    }

    int depth(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + max(depth(root->left), depth(root->right));
    }

    void traversal(TreeNode* root, int depth, int max_depth, vector<vector<int>>& res) {
        if (root == nullptr) {
            return;
        }

        res[max_depth - 1 - depth].push_back(root->val);

        traversal(root->left, depth+1, max_depth, res);
        traversal(root->right, depth+1, max_depth, res);
    }
};


// 使用vector自带的insert函数，结合巧妙的获取插入vector的索引解题
// Warn: vector的insert函数效率较低，该种方法没有上一种方法效率高
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        traversal(root, 0, res);
        return res;
    }

    void traversal(TreeNode* root, int depth, vector<vector<int>>& res) {
        if (root == nullptr) {
            return;
        }

        // tips for adding new level
        if (res.size() == depth) {
            res.insert(res.begin(), vector<int>());
        }

        res[res.size() - 1 - depth].push_back(root->val);
    
        traversal(root->left, depth+1, res);
        traversal(root->right, depth+1, res);
    }
};
