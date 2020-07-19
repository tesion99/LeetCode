/*
递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。

示例1:

 输入：A = 1, B = 10
 输出：10
示例2:

 输入：A = 3, B = 4
 输出：12
提示:

保证乘法范围不会溢出


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recursive-mulitply-lcci
*/
// 利用右移运算符，n << m 等效于 n * 2 ^ m
// 需判断下一次与本次，哪一个距离乘数B更近，从而在A移位后，再进行加减
class Solution {
public:
    int multiply(int A, int B) {
        if (A == 1) return B;
        if (B == 1) return A;
        return multip(A, B, 1, 0);
    }
    int multip(int A, int B, long C, int cnt) {
        if (B == C) {
            return A << cnt;
        }

        long next = C << 1;
        if (B > C && B < next) {
            long tmp = 0;
            if (B - C > next - B) {
                tmp = A << (cnt + 1);
                for (int i = 0; i < next - B; ++i) {
                    tmp -= A;
                }
            } else {
                tmp = A << cnt;
                for (int i = 0; i < B - C; ++i) {
                    tmp += A;
                }
            }
            return tmp;
        }

        return multip(A, B, next, cnt + 1);
    }
};
