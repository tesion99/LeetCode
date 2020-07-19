/*
给你 root1 和 root2 这两棵二叉搜索树。

请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

示例 1：

输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]

提示：

每棵树最多有 5000 个节点。
每个节点的值在 [-10^5, 10^5] 之间。

来源：力扣（LeetCode）
链接：https://dev.lingkou.xyz/problems/all-elements-in-two-binary-search-trees
*/
// BST中序遍历，再合并两个已序数组
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        v1.reserve(5000);
        v2.reserve(5000);
        inorderTraversal(root1, v1);
        inorderTraversal(root2, v2);
        
        auto it1 = v1.begin();
        auto it2 = v2.begin();
        if (v1.empty()) {
            return v2;
        }
        if (v2.empty()) {
            return v1;
        }
        vector<int> res;
        res.reserve(v1.size() + v2.size());
        while (it1 != v1.end() || it2 != v2.end()) {
            if (it1 == v1.end() && it2 == v2.end()) {
                break;
            }
            int value = 0;
            if (it1 != v1.end() && it2 != v2.end()) {
                if (*it1 > *it2) {
                    value = *it2;
                    ++it2;
                } else {
                    value = *it1;
                    ++it1;
                }
                res.push_back(value);
            } else if (it1 != v1.end()) {
                res.insert(res.end(), it1, v1.end());
                it1 = v1.end();
            } else {
                res.insert(res.end(), it2, v2.end());
                it2 = v2.end();
            }
        }
        return res;
    }

    void inorderTraversal(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
};
