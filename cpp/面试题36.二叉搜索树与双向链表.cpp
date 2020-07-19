/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

 

注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
*/
// 中序遍历
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return root;
        }
        vector<Node*> res;
        inorderTraversal(root, res);
        int sz = res.size();
        for (int i = 0; i < sz; ++i) {
            if (i > 0) {
                res[i]->left = res[i - 1];
                res[i - 1]->right = res[i];
            }
        }
        res[0]->left = res[sz - 1];
        res[sz - 1]->right = res[0];
        return res[0];
    }
    void inorderTraversal(Node* root, vector<Node*>& res) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, res);
        res.push_back(root);
        inorderTraversal(root->right, res);
    }
};
