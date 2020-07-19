/*
斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
给定 N，计算 F(N)。

 

示例 1：

输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fibonacci-number
*/
class Solution {
public:
    int fib(int N) {
       if (N <= 1) {
           return N;
        }

        int first = 0, second = 1, tmp = 0;
        for (int i = 2; i <= N; ++i) {
            tmp = first + second;
            first = second;
            second = tmp;
        }
        return tmp;
    }
};
