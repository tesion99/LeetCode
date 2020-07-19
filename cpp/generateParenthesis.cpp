/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
--------------------------
Note: 回溯法
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (0 >= n) {
            return res;
        }

        gen(n, n, string(""), res);
        return res;
    }

    void gen(int left, int right, string str, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }

        if (left > 0) {
            gen(left - 1, right, str + "(", res);
        }

        if (right > left) {
            gen(left, right - 1, str+")", res);
        }
    }
};
