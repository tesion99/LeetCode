/*
给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

注意:

给定的整数保证在32位带符号整数的范围内。
你可以假定二进制数不包含前导零位。
示例 1:

输入: 5
输出: 2
解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
示例 2:

输入: 1
输出: 0
解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-complement
*/
// 取反，统计num有效程度，设定flag保留num有效bit位长度，~num & flag
class Solution {
public:
    int findComplement(int num) {
        int res = ~num;
        int len = 0;
        while (num) {
            ++len;
            num >>= 1;
        }
        // 防止int类型溢出
        long flag = 1;
        flag <<= len;
        flag -= 1;
        return res & flag;
    }
};
