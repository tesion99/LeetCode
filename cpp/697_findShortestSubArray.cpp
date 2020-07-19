/*
给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

示例 1:

输入: [1, 2, 2, 3, 1]
输出: 2
解释: 
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2:

输入: [1,2,2,3,1,4,2]
输出: 6
注意:

nums.length 在1到50,000区间范围内。
nums[i] 是一个在0到49,999范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int arr[50000] = {0};
        map<int, pair<int, int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            ++arr[nums[i]];
            auto it = m.find(nums[i]);
            if (it == m.end()) {
                m[nums[i]] = make_pair(i, i);
            } else {
                it->second.second = i;
            }
        }

        int max_freq = 1;
        vector<int> elems;
        elems.reserve(50000);
        for (int i = 0; i < 50000; ++i) {
            if (arr[i] == max_freq) {
                elems.push_back(i);
            } else if (arr[i] > max_freq) {
                elems.clear();
                max_freq = arr[i];
                elems.push_back(i);
            }
        }
        // 所有数都唯一
        if (max_freq == 1) {
            return 1;
        }
        int min_len = INT_MAX;
        for (auto n : elems) {
            auto it = m.find(n);
            min_len = min(min_len, it->second.second - it->second.first + 1);
        }
        return min_len;
    }
};
