/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
---------------------------------
Note: 类似层序遍历，对比每一层是否对称
*/
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        if (root->left == nullptr && root->right == nullptr) return true;

        queue<vector<TreeNode*>> levels;
        vector<TreeNode*> level;

        if (root->left) level.push_back(root->left);
        if (root->right) level.push_back(root->right);

        levels.push(level);
        while (!levels.empty()) {
            vector<TreeNode*>& nodes = levels.front();
            // 需要对称，除第一层外，后续所有层节点个数为偶数个
            if (nodes.size() % 2 != 0) {
                return false;
            }

            int start = 0, end = nodes.size() - 1;
            while (start < end) {
                if (nodes[start]->val != nodes[end]->val) return false;
                // 判断后续子节点的有效性
                if ((nodes[start]->left == nullptr && nodes[end]->right != nullptr) ||
                    (nodes[start]->left != nullptr && nodes[end]->right == nullptr)) {
                        return false;
                    }

                if ((nodes[start]->right == nullptr && nodes[end]->left != nullptr) ||
                    (nodes[start]->right != nullptr && nodes[end]->left == nullptr)) {
                        return false;
                    }
                ++start;
                --end;
            }

            vector<TreeNode*> new_level;
            for (int i = 0,sz = nodes.size(); i < sz; ++i) {
                if (nodes[i]->left) new_level.push_back(nodes[i]->left);
                if (nodes[i]->right) new_level.push_back(nodes[i]->right);
            }

            if (!new_level.empty()) {
                levels.push(new_level);
            }
            levels.pop();
        }

        return true;
    }
};


// 当一个树对称时，其左右两个子树，翻转右子树后，右子树应该与左子树相等
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        if (root->left == nullptr && root->right == nullptr) return true;

        // 翻转右子树
        TreeNode* right = revert(root->right);
        // 如果对称，则翻转后左右两颗子树应该相同
        return isSame(root->left, root->right);
    }

    TreeNode* revert(TreeNode* root) {
        if (root == nullptr) return root;
        
        revert(root->left);
        revert(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }

    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr && t2 != nullptr) return false;
        if (t1 != nullptr && t2 == nullptr) return false;

        if (t1->val != t2->val) return false;

        return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
    }
};


// 官方题解
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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;

        return t1->val == t2->val &&
                isMirror(t1->left, t2->right) &&
                isMirror(t1->right, t2->left);
    }
};
