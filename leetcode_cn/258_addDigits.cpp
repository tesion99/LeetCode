/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
进阶:
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-digits
*/
// 观察规律
// 1~9 个位数字和结果，直接返回
// 10~18个位数字和结果，重复1~9
// 后续更多观察发现，每9个数后，结果重复
// 故取 num % 9，检测余数即可
class Solution {
public:
    int addDigits(int num) {
        if (num <= 0) {
            return 0;
        }
        int mod = num % 9;
        return mod == 0 ? 9 : mod;
    }
};
