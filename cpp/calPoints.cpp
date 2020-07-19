/*
你现在是棒球比赛记录员。
给定一个字符串列表，每个字符串可以是以下四种类型之一：
1.整数（一轮的得分）：直接表示您在本轮中获得的积分数。
2. "+"（一轮的得分）：表示本轮获得的得分是前两轮有效 回合得分的总和。
3. "D"（一轮的得分）：表示本轮获得的得分是前一轮有效 回合得分的两倍。
4. "C"（一个操作，这不是一个回合的分数）：表示您获得的最后一个有效 回合的分数是无效的，应该被移除。

每一轮的操作都是永久性的，可能会对前一轮和后一轮产生影响。
你需要返回你在所有回合中得分的总和。

示例 1:

输入: ["5","2","C","D","+"]
输出: 30

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/baseball-game
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int res = 0;
        for (int i = 0, sz = ops.size(); i < sz; ++i) {
            if (ops[i] != "+" && ops[i] != "D" && ops[i] != "C") {
                st.push(stoi(ops[i]));
                continue;
            }

            if (ops[i] == "+") {
                int val = st.top();
                st.pop();
                int score = val + st.top();
                st.push(val);
                st.push(score);
            } else if (ops[i] == "D") {
                st.push(st.top() * 2);
            } else {
                // C
                st.pop();
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
