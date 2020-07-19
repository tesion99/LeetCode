/*
不使用运算符 + 和 - ，计算两整数 a 、b 之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
*/
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int tmp = a ^ b; // 计算无进位加法
            b = (unsigned int)(a & b) << 1; // 计算进位
            a = tmp;
        }
        return a;
    }
};
