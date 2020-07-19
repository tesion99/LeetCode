/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // 打劫第一家与最后一家不能同时打劫
        // 一定打劫第一家
        int sz = nums.size();
        vector<int> ans(sz, 0);
        ans[0] = 0;
        ans[1] = nums[0];
        for (int i = 2; i < sz; ++i) {
            ans[i] = max(nums[i-1] + ans[i - 2], ans[i - 1]);
        }
        int first_rob = ans[sz - 1];
        // 一定打劫最后一家
        ans[0] = 0;
        ans[1] = nums[1];
        for (int i = 2; i < sz; ++i) {
            ans[i] = max(nums[i] + ans[i - 2], ans[i - 1]);
        }
        int last_rob = ans[sz - 1];
        return max(first_rob, last_rob);
    }
};
