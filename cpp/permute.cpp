/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

Ps:
    利用递归方式，先固定一位，然后子序列全排列，然后该固定位与后续元素逐个交换位置，在局部全排列
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        if (!nums.empty()) {
            permute_core(nums, 0, nums.size() - 1, res);
        }

        return res;
    }

    void permute_core(vector<int>& nums, int start, int end, vector<vector<int>>& res) {
        if (start == end) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i <= end; ++i) {
            int cur = nums[i];
            nums[i] = nums[start];
            nums[start] = cur;
            permute_core(nums, start + 1, end, res);
            cur = nums[i];
            nums[i] = nums[start];
            nums[start] = cur;
        }
    }
};
