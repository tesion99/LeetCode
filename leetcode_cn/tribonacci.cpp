/*
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

 

示例 1：

输入：n = 4
输出：4
解释：
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
*/
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int one = 0;
        int two = 1;
        int three = 1;
        int cur = 0;
        for (int i = 3; i <= n; ++i) {
            cur = one + two + three;
            one = two;
            two = three;
            three = cur;
        }
        return cur;
    }
};
