/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
----------------------
Note:
    注意溢出条件的检测
*/

class Solution {
public:
    int reverse(int x) {
        int sign = (x >= 0) ? 1 : -1;
        int res = 0;

        if (x == INT_MIN) return 0;

        if (x < 0) x *= -1;

        while (x) {
            if (res > INT_MAX / 10.0) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res * sign;
    }
};
