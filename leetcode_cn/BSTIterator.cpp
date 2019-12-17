/*
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search-tree-iterator
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        root_ = root;
        traversal(root_, st_);
    }

    /** @return the next smallest number */
    int next() {
        int value = st_.top()->val;
        st_.pop();
        return value;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st_.empty();
    }

    void traversal(TreeNode* root, stack<TreeNode*>& st) {
        if (root == nullptr) return;

        traversal(root->right, st);
        st_.push(root);
        traversal(root->left, st);
    }
private:
    TreeNode* root_;
    stack<TreeNode*> st_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
