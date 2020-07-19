/*
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-four
*/
// 判断是否为2的幂
// 然后判断奇数位是否为1
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 4 && num != 1) {
            return false;
        }
        if ((num & (num - 1)) != 0) {
            return false;
        }

        return (num & (0x55555555)) == num;
    }
};
