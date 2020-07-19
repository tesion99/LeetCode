/*
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res = 0;
        for (int i = 0, sz = tokens.size(); i < sz; ++i) {
            if (tokens[i] != "+" && tokens[i] != "-"
                && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
                continue;
            }

            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();

            if (tokens[i] == "+") {
                st.push(num2 + num1);
            } else if (tokens[i] == "-") {
                st.push(num2 - num1);
            } else if (tokens[i] == "*") {
                st.push(num2 * num1);
            } else {
                st.push(num2 / num1);
            }
        }

        if (!st.empty()) res = st.top();

        return res;
    }
};
