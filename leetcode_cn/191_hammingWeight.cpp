/*
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

 

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-1-bits
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            if (n & 1) {
                ++cnt;
            }
            n >>= 1;
        }
        return cnt;
    }
};
// 使用n & n - 1 打掉最后一位 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            if (n & 1) {
                ++cnt;
                n &= n - 1;
            } else {
                n >>= 1;
            }
        }
        return cnt;
    }
};
