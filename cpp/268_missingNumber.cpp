/*
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int sz = nums.size();
        int total = (sz + 1) * sz / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return total - sum;
    }
};
