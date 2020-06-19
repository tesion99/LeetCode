/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，

分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
*/
// 两个栈，一个用于追加，存储的是逆序的数据，一个用于弹出，存储的是正常入队的数据
// 1. 入队时，将数据追加到逆序的栈中，此处为data
// 2. 出队时，需要将data中的数据逐个弹出到tmp中，tmp中存储的是正常的入队的数据
// 3. 当后续在执行弹出时，需先弹出tmp中的数据，如果tmp为空，执行步骤2的操作
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        data.push(value);
    }
    
    int deleteHead() {
        if (tmp.empty() && data.empty()) {
            return -1;
        }

        int value = -1;
        if (!tmp.empty()) {
            value = tmp.top();
            tmp.pop();
        } else {
            size_t sz = data.size();
            while (sz > 1) {
                tmp.push(data.top());
                data.pop();
                --sz;
            }
            value = data.top();
            data.pop();
        }
        return value;
    }
private:
    stack<int> data;
    stack<int> tmp;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
