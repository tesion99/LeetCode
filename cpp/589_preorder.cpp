/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

 



 

返回其前序遍历: [1,3,5,6,2,4]。

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal
*/

// 递归
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(Node* root, vector<int>& data) {
        if (!root) return;

        data.push_back(root->val);
        for (auto node : root->children) {
            preorder(node, data);
        }
    }
};

// 迭代法
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        Node* cur = root;
        while (cur || !st.empty()) {
            if (!cur) {
                cur = st.top();
                st.pop();
            }
            
            res.push_back(cur->val);
            if (cur->children.empty()) {
                cur = nullptr;
            } else {
                for (int i = cur->children.size() - 1; i > 0; --i) {
                    st.push(cur->children[i]);
                }
                cur = cur->children[0];
            }
        }
        return res;
    }
};
