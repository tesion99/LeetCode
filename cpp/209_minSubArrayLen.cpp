/*
给定一个含有 n 个正整数的数组和一个正整数 s ，

找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。

如果不存在符合条件的子数组，返回 0。
 

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 

进阶：

如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
*/
/*
使用双指针，一个指向子区间的开始，一个指向末尾
当子区间总和<s时，尾指针移动
当子区间总和>=s时，需更新结果，然后首指针移动，去除首元素，看剩余的子区间和是否仍然满足>=s的条件
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, cur = 0, sum = 0;
        int sz = nums.size(), res = 0;
        while (cur < sz) {
            sum += nums[cur];
            while (sum >= s) {
                int cnt = cur - start + 1;
                res = (res == 0) ? cnt : min(res, cnt);
                sum -= nums[start];
                ++start;
            }
            ++cur;
        }
        return res;
    }
};
