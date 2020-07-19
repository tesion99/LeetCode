/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
*/
// 回溯，没去求取剩余数字的sqrt,从1~sqrt中选择一个数参与组合
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        int cnt = 0, res = INT_MAX;
        backtrace(n, cnt, res);
        return res;
    }

    void backtrace(int n, int cnt, int& res) {
        if (cnt >= res) {
            return;
        }
        if (n <= 0) {
            res = min(cnt, res);
            return;
        }

        int root = sqrt(n);
        for (int i = root; i >= 1; --i) {
            backtrace(n - i * i, cnt + 1, res);
        }
    }
};
