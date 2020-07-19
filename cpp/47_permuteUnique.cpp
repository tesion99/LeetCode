/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
*/
// 回溯，排序比对每轮回溯中的前后值，避免重复
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        }

        vector<int> tmp;
        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());
        tmp.reserve(nums.size());
        dfs(nums, visited, tmp, res);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& tmp, vector<vector<int>>& res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        }

        bool flag = false;
        int pre = 0;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            if (flag && pre == nums[i]) {
                continue;
            }

            if (!visited[i]) {
                flag = true;
                pre = nums[i];
                visited[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, visited, tmp, res);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }
};
