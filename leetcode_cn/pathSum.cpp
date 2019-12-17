/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
*/

// 使用迭代方式，保存每一条路径的结点，若复合需求，则进行插入结果操作
// 此种方式复制拷贝过多，效率较低
// TODO: 使用回溯法，复合条件时，从底层逐步向上回溯，避免冗余数据
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        hasPathSum(root, sum, vector<int>(), res);
        return res;
    }

    bool hasPathSum(TreeNode* root, int sum, vector<int> tmp, vector<vector<int>>& res) {
        if (root == nullptr) return false;

        tmp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                res.push_back(tmp);
                return true;
            } 
            return false;
        }

        bool left = hasPathSum(root->left, sum - root->val, tmp, res);
        bool right = hasPathSum(root->right, sum - root->val, tmp, res);
        return left || right;
    }
};

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        hasPathSum(root, sum, res);
        return res;
    }

    int hasPathSum(TreeNode* root, int sum, vector<vector<int>>& res) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                vector<int> tmp(1, root->val);
                res.push_back(move(tmp));
                return 1;
            } 
            return 0;
        }

        // 根据左右子树插入的解vector的个数，确定将本节点插入哪些vector中
        int left = hasPathSum(root->left, sum - root->val, res);
        int right = hasPathSum(root->right, sum - root->val, res);

        size_t sz = res.size();
        for (int i = sz - left - right; i < sz; ++i) {
            res[i].insert(res[i].begin(), root->val);
        }
        return left + right;
    }
};

// 回溯
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        pathSum(root, sum, tmp, res);
        return res;
    }

    void pathSum(TreeNode* root, int sum, vector<int>& tmp, vector<vector<int>>& res) {
        if (root == nullptr) return;

        // use backstrace
        tmp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            res.push_back(tmp);
        } else {
            pathSum(root->left, sum - root->val, tmp, res);
            pathSum(root->right, sum - root->val, tmp, res);
        }
        tmp.pop_back();
    }
};
