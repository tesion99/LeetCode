/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。

在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 

限制：

1 <= 数组长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof
*/
// 题意有误，应该是值在0~n范围内，其中n为数组长度
// 利用数学公式求0 ~ n 所有连续数字和，减去当前数组中的数字和，得到缺失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = (0 + nums.size()) * (nums.size() + 1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return total - sum;
    }
};
