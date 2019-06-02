/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        index_ = -1;
    }

    void push(int x) {
        ++index_;
        data_.insert(std::pair<int, int>(x, index_));
    }

    void pop() {
        for (auto it = data_.begin(); it != data_.end(); ++it) {
            if (it->second == index_) {
                data_.erase(it);
                --index_;
                break;
            }
        }
    }

    int top() {
        if (index_ < 0) return -1;

        auto it = data_.begin();
        for (; it != data_.end(); ++it) {
            if (it->second == index_) break;
        }

        return it->first;
    }

    int getMin() {
        if (index_ < 0) return -1;

        return data_.begin()->first;
    }

    multimap<int, int> data_;
    int index_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        auto res = data_.insert(x);
        st_.push(res);
    }

    void pop() {
        if (st_.empty()) return;

        auto it = st_.top();
        data_.erase(it);
        st_.pop();
    }

    int top() {
        if (st_.empty()) return -1;

        auto it = st_.top();
        return *it;
    }

    int getMin() {
        if (data_.empty()) return -1;

        return *data_.begin();
    }

    multiset<int> data_;
    stack<multiset<int>::iterator> st_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
