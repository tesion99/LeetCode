/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmp, res);
        return res;
    }

    void dfs(vector<int>& nums, int start, vector<int>& tmp, vector<vector<int>>& res) {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); ++i) {
            // 同一层次回溯，避免加入重复数据
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(nums, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};
