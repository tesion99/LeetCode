/*
设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。

示例 1:

输入: nums = [5,6,5], target = 11
输出: [[5,6]]
示例 2:

输入: nums = [5,6,5,6], target = 11
输出: [[5,6],[5,6]]
提示：

nums.length <= 100000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pairs-with-sum-lcci
*/
// 借助hash表，记录需要目标数的个数，避免重复计算
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> m;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            auto it = m.find(nums[i]);
            if (it == m.end()) {
                ++m[target - nums[i]];
            } else {
                res.push_back({target - it->first, it->first});
                --it->second;
                if (it->second <= 0) {
                    m.erase(it);
                }
            }
        }
        return res;
    }
};

// 排序，双指针
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (sum > target) {
                --end;
            } else if (sum < target) {
                ++start;
            } else {
                res.push_back({nums[start], nums[end]});
                --end;
                ++start;
            }
        }
        return res;
    }
};
