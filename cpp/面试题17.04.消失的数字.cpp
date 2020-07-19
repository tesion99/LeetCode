/*
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

注意：本题相对书上原题稍作改动

示例 1：

输入：[3,0,1]
输出：2
 

示例 2：

输入：[9,6,4,2,3,5,7,0,1]
输出：8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number-lcci
*/
// 统计0~n所有数字的总和total
// total - sum(nums)即得到缺失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n+1) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return total - sum;
    }
};
