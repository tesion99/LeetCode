/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
提示：

0 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
*/
// 有题意知, F(n) = F(n - 1) + F(n - 2)
// 其中F(0) = 1, F(1) = 1
// 其他与斐波那契数列相同
class Solution {
public:
    int numWays(int n) {
        if (n <= 1) {
            return 1;
        }
        int first = 1, second = 1;
        int cur = 0;
        for (int i = 2; i <= n; ++i) {
            cur = (first + second) % 1000000007;
            first = second;
            second = cur;
        }
        return cur;
    }
};
