/*
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

 

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

输出：[7,4,1]

解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1

注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
 

提示：

给定的树是非空的，且最多有 K 个结点。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree
*/
// 本题不是简单的求depth之差为K的问题
// 1. 观察到从target节点，只需向下搜索高度差为K的子节点
// 2. 对于target的parent节点，需要搜索其另一子树（可能是left或right)，
//    统计距离 K - 1，从该子树出发搜索高度差为K - 1的点，处理过程与步骤1相同
// 3. 再对target的parent的parent节点做类似2的操作
// 综上，发现我们只需记录从root 到 target 上经过的路径节点集合path，
// 再以path中的每个结点为开始结点，搜索深度差为某一固定值的子节点即可
// Note: 需要避免path路径上的节点被重复搜索
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // 先深度优先，寻找到从root 到 target的节点路径
        vector<int> res;
        vector<TreeNode*> path;

        findTarget(root, target, path);
        int sz = path.size();
        // 寻找到path路径节点后，问题变为从path上的节点出发，到固定depth的问题
        for (int i = path.size() - 1; i >= 0 && K >= 0; --i) {
            if (K == 0) {
                res.push_back(path[i]->val);
                break;
            }
            if (i == sz - 1) {
                getNode(path[i], i, i + K, res);
            } else {
                // 广度优先，搜索非路径节点的其他子树
                TreeNode* p = (path[i]->left == path[i + 1]) ? path[i]->right : path[i]->left;
                getNode(p, i + 1, K + i, res);   // i + 1 + K - 1 ==> K + i
            }
            --K;
        }
        return res;
    }
    bool findTarget(TreeNode* root, TreeNode* target, vector<TreeNode*>& nodes) {
        if (root == nullptr) {
            return false;
        }
        nodes.push_back(root);
        if (root == target) {
            return true;
        }
        bool ret = findTarget(root->left, target, nodes);
        if (!ret && root->left) {
            nodes.pop_back();
        }
        if (!ret) {
            ret = findTarget(root->right, target, nodes);
            if (!ret && root->right) {
                nodes.pop_back();
            }
        }
        return ret;
    }
    void getNode(TreeNode* root, int depth, int k, vector<int>& res) {
        if (root == nullptr || depth > k) {
            return;
        }
        if (depth == k) {
            res.push_back(root->val);
            return;
        }
        ++depth;
        getNode(root->left, depth, k, res);
        getNode(root->right, depth, k, res);
    }
};
