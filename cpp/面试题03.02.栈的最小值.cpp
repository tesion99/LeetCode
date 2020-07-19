/*
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。


示例：

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack-lcci
*/
// 使用stack执行push pop top操作
// 使用map记录栈中值的大小顺序
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        ++md_[x];
        st_.push(x);
    }
    
    void pop() {
        if (!st_.empty()) {
            int value = st_.top();
            st_.pop();
            auto it = md_.find(value);
            if (it->second == 1) {
                md_.erase(it);
            } else {
                --it->second;
            }
        }
    }
    
    int top() {
        return st_.top();
    }
    
    int getMin() {
        return md_.begin()->first;
    }
private:
    map<int, int> md_;
    stack<int> st_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
