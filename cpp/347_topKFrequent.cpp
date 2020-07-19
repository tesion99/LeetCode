/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> m;
        map<int, vector<int>> freq;
        for (auto n : nums) {
            ++m[n];
        }
        for (auto& p : m) {
            freq[p.second].push_back(p.first);
        }
        auto it = freq.rbegin();
        while (k > 0 && it != freq.rend()) {
            int sz = it->second.size();
            int rest = min(k, sz);
            for (int i = sz - 1; i >= (sz - rest); --i) {
                res.push_back(it->second[i]);
            }
            k -= rest;
            ++it;
        }
        return res;
    }
};
