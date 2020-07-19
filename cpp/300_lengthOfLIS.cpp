/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
*/
// 选定第一个元素，回溯遍历后续元素是否添加
// TODO: 数据过大时执行超时，带改进
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0, len = 0, sz = nums.size();

        for (int i = 0; i < sz; ++i) {
            int next = nums[i];
            len = 1;
            helper(nums, next, i + 1, len, res);
        }
        return res;
    }
    void helper(vector<int>& n, int next, int cur, int len, int& res) {
        if (cur == n.size()) {
            res = max(res, len);
            return;
        }
        if (n[cur] > next) {
            helper(n, n[cur], cur + 1, len + 1, res);
        }
        helper(n, next, cur + 1, len, res);
    }
};
