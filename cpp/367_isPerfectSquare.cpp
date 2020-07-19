/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
*/
// 折半查找
// 在mid = num/2 与 num/mid之间比较
// 当mid < num / mid时返回false，因为出现5x3 3x5的循环情况
// Note: 注意使用mid*mid，(mid + rest)/2导致溢出的情况
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }

        int mid = num / 2;
        while (true) {
            int rest = num / mid;
            if (mid == rest) {
                break;
            } else if (mid < rest) {
                return false;
            } else {
                mid = rest + (mid - rest) / 2;
            }
        }
        return num % mid == 0;
    }
};
