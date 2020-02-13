/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
*/
// 对每个区间，按第一个元素排序，便于合并
// 记录当前区间的起始，start, end
// 遍历排序后的区间，更新start，end
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) {
            return vector<vector<int>>();
        }
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>&b){
            return a[0] < b[0];
        });

        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1, sz = intervals.size(); i < sz; ++i) {
            if (intervals[i][0] > end) {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back(vector<int>{start, end});

        return res;
    }
};
