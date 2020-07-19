/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
--------------------------
Note: 使用两个queue，一个用于存放数据，一个用于交换数据，作临时缓冲
*/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        input_.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        size_t sz = input_.size();
        while (sz-- != 1) {
            output_.push(input_.front());
            input_.pop();
        }

        int value = input_.front();
        input_.pop();
        sz = output_.size();
        while (sz-- > 0) {
            input_.push(output_.front());
            output_.pop();
        }

        return value;
    }

    /** Get the top element. */
    int top() {
        int value = pop();
        input_.push(value);
        return value;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return input_.empty();
    }

private:
    queue<int> input_;
    queue<int> output_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
