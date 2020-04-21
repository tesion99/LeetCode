/*
括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

说明：解集不能包含重复的子集。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bracket-lcci
*/
// 分别记录字符(与字符)的个数, a与b
// 当a < n 时可放入(
// 当a > b 时可放入)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 0) {
            return {};
        }
        string s;
        vector<string> res;
        helper(n, 0, 0, s, res);
        return res;
    }
    void helper(int n, int a, int b, string& s, vector<string>& res) {
        if (a > n || b > n || b > a) {
            return;
        }
        if (a == n && b == n) {
            res.push_back(s);
            return;
        }

        if (a < n) {
            s.push_back('(');
            helper(n, a + 1, b, s, res);
            s.pop_back();
        }
        if (a > b) {
            s.push_back(')');
            helper(n, a, b + 1, s, res);
            s.pop_back();
        }
    }
};
