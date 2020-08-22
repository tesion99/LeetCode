/*
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。

val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。
    如果 index 等于链表的长度，则该节点将附加到链表的末尾。
    如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 

示例：

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
 

提示：

所有val值都在 [1, 1000] 之内。
操作次数将在  [1, 1000] 之内。
请不要使用内置的 LinkedList 库。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-linked-list
*/
// 保存链表的头尾节点指针，以及列表长度
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head_ = nullptr;
        rear_ = nullptr;
        size_ = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index > size_ - 1) return -1;
        ListNode* p = head_;
        while (p && index > 0) {
            p = p->next;
            --index;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        if (head_) {
            node->next = head_;
        }
        if (!rear_) {
            rear_ = node;
        }
        head_ = node;
        ++size_;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if (rear_) {
            rear_->next = node;
        }
        if (!head_) {
            head_ = node;
        }
        rear_ = node;
        ++size_;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size_) return;

        if (index <= 0) {
            addAtHead(val);
        } else if (index == size_) {
            addAtTail(val);
        } else if (index > 0 && index < size_) {
            ListNode* p = head_, * prev = nullptr;
            ListNode* node = new ListNode(val);
            while (p && index > 0) {
                prev = p;
                p = p->next;
                --index;
            }
            node->next = p;
            prev->next = node;
            ++size_;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size_) return;

        ListNode* p = head_, * prev = nullptr;
        if (index == 0) {
            head_ = head_->next;
        } else {
           while (p && index > 0) {
               prev = p;
               p = p->next;
               --index;
           }
           if (p == rear_) {
               rear_ = prev;
           }
           prev->next = p->next;
        }
        delete p;
        --size_;
        if (size_ == 0) {
            head_ = nullptr;
            rear_ = nullptr;
        }
    }
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int value) : val(value), next(nullptr) {}
    };
ListNode* head_;
ListNode* rear_;
int size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
