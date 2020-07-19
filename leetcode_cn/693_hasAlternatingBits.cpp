/*
给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

示例 1:

输入: 5
输出: True
解释:
5的二进制数是: 101
示例 2:

输入: 7
输出: False
解释:
7的二进制数是: 111

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-number-with-alternating-bits
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = -1, cur = 0;
        while (n) {
            cur = n & 1;
            if (pre == cur) {
                return false;
            } else {
                pre = cur;
            }
            n >>= 1;
        }
        return true;
    }
};
