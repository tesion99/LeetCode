/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/target-sum
*/
// 回溯，暴力破解
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0;
        backtrace(nums, 0, 0, S, res);
        return res;
    }

    void backtrace(vector<int>& nums, int idx, int sum, int target, int& res) {
        if (idx == nums.size()) {
            if (sum == target) {
                ++res;
            }
            return;
        }
        
        backtrace(nums, idx + 1, sum + nums[idx], target, res);
        backtrace(nums, idx + 1, sum - nums[idx], target, res);
    }
};
// 动态规划
// DP[S] = DP[S + nums[i] + DP[S - nums[i]
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) {
            return 0;
        }

        map<pair<int,int>, int> dp;
        //dp[S] = dp[S - nums[i]] + dp[S+nums[i]];
        return dfs(nums, nums.size() - 1, dp, S);
    }

    int dfs(vector<int>& nums, int idx, map<pair<int,int>,int>& dp, long target) {
        auto it = dp.find(make_pair(idx, target));
        if (it != dp.end()) {
            return it->second;
        }

        if (idx == 0) {
            if (nums[idx] == target || nums[idx] == -target) {
                return nums[idx] == 0 ? 2 : 1;  // 为0时需特殊处理
            }
            return 0;
        }
        int plus = dfs(nums, idx - 1, dp, target + nums[idx]);
        int minus = dfs(nums, idx - 1, dp, target - nums[idx]);
        dp[make_pair(idx - 1, target+nums[idx])] = plus;
        dp[make_pair(idx - 1, target-nums[idx])] = minus;
        dp[make_pair(idx, target)] = plus + minus;
        return plus + minus;
    }
};
