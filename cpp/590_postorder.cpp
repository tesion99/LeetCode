/*
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

 



 

返回其后序遍历: [5,6,3,2,4,1].
*/
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
    set<Node*> visited;
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    void postorder(Node* root, vector<int>& res) {
        if (!root || visited.count(root)) return;

        for (int i = 0; i < root->children.size(); ++i) {
            postorder(root->children[i], res);
        }

        visited.insert(root);
        res.push_back(root->val);
        postorder(root, res); // 记录已经访问过的节点，避免此处后续再次访问
    }
};
