/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Ps:
    每个元素在结果集中只有出现和不出现2种状态
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> pre;
        subsetcore(nums, 0, nums.size() - 1, pre, res);
        return res;
    }

    void subsetcore(vector<int> & nums, int cur, int end, vector<int> pre, vector<vector<int>> & res)
    {
        if (cur > end) {
            res.push_back(pre);
            return;
        }

        subsetcore(nums, cur+1, end, pre, res);
        pre.push_back(nums[cur]);
        subsetcore(nums, cur+1, end, pre, res);
    }
};


// 回溯版本
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(nums, 0, tmp, res);
        return res;
    }

    void backtrace(vector<int>& nums, int start, vector<int>& tmp, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(tmp);
            return;
        }

        // 不放入当前元素
        backtrace(nums, start+1, tmp, res);
        // 放入当前元素
        tmp.push_back(nums[start]);
        backtrace(nums, start+1, tmp, res);
        tmp.pop_back();
    }
};
