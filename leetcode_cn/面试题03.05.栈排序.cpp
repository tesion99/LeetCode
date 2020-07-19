/*
栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。

该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

示例1:

 输入：
["SortedStack", "push", "push", "peek", "pop", "peek"]
[[], [1], [2], [], [], []]
 输出：
[null,null,null,1,null,2]
示例2:

 输入： 
["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
[[], [], [], [1], [], []]
 输出：
[null,null,null,null,null,true]
说明:

栈中的元素数目在[0, 5000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-of-stacks-lcci
*/
// 借助缓冲栈，弹出较小的数据，找到插入数据合适的位置
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        while (!data_.empty() && data_.top() < val) {
            tmp_.push(data_.top());
            data_.pop();
        }
        data_.push(val);
        while (!tmp_.empty()) {
            data_.push(tmp_.top());
            tmp_.pop();
        }
    }
    
    void pop() {
        if (!data_.empty()) {
            data_.pop();
        }
    }
    
    int peek() {
        return data_.empty() ? -1 : data_.top();
    }
    
    bool isEmpty() {
        return data_.empty();
    }
private:
    stack<int> data_;
    stack<int> tmp_;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
