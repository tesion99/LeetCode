/*
给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

 

示例：



输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
 

提示：

树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-nodes-and-return-forest
*/
// 1. 删除节点时，产生的新树的根节点需要一个集合记录
// 2. 删除当前结点时，需要设置其父节点的左子树或右子树指针为null
// 3. 需要一个状态标志当前结点，为左孩子还是右孩子
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
    map<int, TreeNode*> rootMap;
    set<int> delSet;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) return {};
        if (to_delete.empty()) return {root};

        vector<TreeNode*> res;
        delSet = set<int>(to_delete.begin(), to_delete.end());

        rootMap.insert({root->val, root});
        Delete(nullptr, root, true);
        for (auto& p : rootMap) {
            res.push_back(p.second);
        }
        return res;
    }

    void Delete(TreeNode* parent, TreeNode* cur, bool isLeft) {
        if (cur == nullptr || delSet.empty()) return;
        
        if (delSet.count(cur->val)) {
            if (parent != nullptr) {
                if (isLeft) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            } else {
                // cur 为父节点
                rootMap.erase(cur->val);
            }
            
            if (cur->left) {
                rootMap.insert({cur->left->val, cur->left});
            }
            if (cur->right) {
                rootMap.insert({cur->right->val, cur->right});
            }

            delSet.erase(cur->val);
            Delete(nullptr, cur->left, true);
            Delete(nullptr, cur->right, false);
            
            return;
        }

        Delete(cur, cur->left, true);
        Delete(cur, cur->right, false);
    }
};
