/*
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
*/
// DP[i] = max(DP[i-1] + nums[i], nums[i])
// res = max(res, DP[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], cur_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cur_sum + nums[i] < nums[i]) {
                cur_sum = nums[i];
            } else {
                cur_sum += nums[i];
            }
            res = max(cur_sum, res);
        }
        return res; 
    }
};
