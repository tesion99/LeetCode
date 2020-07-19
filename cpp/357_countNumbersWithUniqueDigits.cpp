/*
给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。

示例:

输入: 2
输出: 91 
解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits
*/
// 回溯，记录数字中已经访问过的数字
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 0 || n > 10) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        vector<bool> visited(10, false);
        string s;
        s.reserve(10);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            backtrace(i, visited, s, res);
        }
        return res;
    }
    void backtrace(int n, vector<bool>& visited, string& s, int& res) {
        if (s.size() >= 2 && s[0] == '0') {
            return;
        }
        if (n == 0) {
            ++res;
            return;
        }
        for (int i = 0; i < 10; ++i) {
            if (!visited[i]) {
                s.push_back(i+'0');
                visited[i] = true;
                backtrace(n - 1, visited, s, res);
                visited[i] = false;
                s.pop_back();
            }
        }
    }
};
