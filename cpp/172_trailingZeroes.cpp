/*
给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:

输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/factorial-trailing-zeroes
*/
// 递归统计每轮中剩余能被5整除的个数以及能被2整除的个数，取两者个数的最小值
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        int res = 0;
        int fives = n / 5;
        int twos = n / 2;
        while (fives && twos) {
            res += min(fives, twos);
            fives /= 5;
            twos /= 2;
        }
        return res;
    }
};
