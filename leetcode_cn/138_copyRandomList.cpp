/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 

示例 1：


输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：


输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：


输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 

提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。
*/
// 优化，加入反向映射
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* pre = &dummy, * ph = head;
        map<Node*, int> m;  // 对原链表做正向映射
        map<int, Node*> mp; // 对新链表做反向映射，便于查找random指针
        int i = 0;
        // 首先复制整条链表，除了random指针
        // 同时对节点进行编号，便于后续查找
        while (ph) {
            pre->next = new Node(ph->val);
            pre = pre->next;
            mp[i] = pre;
            m[ph] = i;
            ph = ph->next;
            ++i;
        }
        // 再次遍历，设置节点的random指针
        pre = dummy.next;
        ph = head;
        while (pre) {
            pre->random = ph->random ? mp[m[ph->random]] : nullptr;
            pre = pre->next;
            ph = ph->next;
        }
        return dummy.next;
    }
};