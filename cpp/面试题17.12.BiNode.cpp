/*
二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求值的顺序保持不变，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

返回转换后的单向链表的头节点。

注意：本题相对原题稍作改动

 

示例：

输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
提示：

节点数量不会超过 100000。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binode-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 类似将BST转换为双向链表，本质为中序遍历
// 使用全局变量head与pre记录链表的头尾节点
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
    TreeNode* head = nullptr, * pre = nullptr;
    TreeNode* convertBiNode(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        convertBiNode(root->left);
        if (head == nullptr) {
            head = root;
        } else {
            pre->right = root;
        }
        pre = root;
        root->left = nullptr;
        convertBiNode(root->right);
        return head;
    }
};
