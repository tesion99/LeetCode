/*
三合一。描述如何只用一个数组来实现三个栈。

你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

构造函数会传入一个stackSize参数，代表每个栈的大小。

示例1:

 输入：
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 输出：
[null, null, null, 1, -1, -1, true]
说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
示例2:

 输入：
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 输出：
[null, null, null, null, 2, 1, -1, -1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-in-one-lcci
*/
class TripleInOne {
public:
    TripleInOne(int stackSize) {
        datas_ = vector<vector<int>>(3, vector<int>());
        cap_ = stackSize;
    }

    void push(int stackNum, int value) {
        if (datas_[stackNum].size() >= cap_) return;
        datas_[stackNum].push_back(value);
    }

    int pop(int stackNum) {
        int value = datas_[stackNum].empty() ? -1 : datas_[stackNum].back();
        if (!datas_[stackNum].empty()) datas_[stackNum].pop_back();
        return value;
    }

    int peek(int stackNum) {
        return datas_[stackNum].empty() ? -1 : datas_[stackNum].back();
    }

    bool isEmpty(int stackNum) {
        return datas_[stackNum].empty();
    }
private:
    vector<vector<int>> datas_;
    int cap_;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
