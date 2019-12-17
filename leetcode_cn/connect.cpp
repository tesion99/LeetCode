/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        // 层序遍历, BFS
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* pre = nullptr;
            while (n-- > 0) {
                Node* cur = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (pre) pre->next = cur;
                pre = cur;
                q.pop();
            }
            pre == nullptr;
        }
        return root;
    }
};


// 使用类似层序遍历方式，结合next指针，实现上下层的遍历连接
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        Node * pre = nullptr, * cur = nullptr;
        Node * start = root;

        while (start) {
            pre = start; // 上一层开始结点
            cur = start->left;  // 下一层开始结点
            if (cur == nullptr) {    // 下一层为空，直接退出
                break;
            }
            while (pre) {
                pre->left->next = pre->right;
                if (pre->left != cur) {
                    cur->next = pre->left;  // pre cur不为父子结点关系
                } 
                cur = pre->right; // cur指向已连接的最右的结点
                pre = pre->next;
            }
            start = start->left;    // 进入下一层
        }
        return root;
    }
};
