/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/summary-ranges
*/
// 区间首尾相连，需要记录每个区间的开始start, 与前一个坐标pre以及当前cur
// 对于到结尾处，也需将结果保存
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        if (1 == nums.size()) {
            return {to_string(nums[0])};
        }

        int start = 0, pre = 0;
        ostringstream oss;
        vector<string> res;

        for (int i = 1; pre < nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[pre] + 1) {
                if (start == pre) {
                    oss << nums[start];
                } else {
                    oss << nums[start] << "->" << nums[pre];
                }
                res.push_back(oss.str());
                oss.str("");
                start = i;
            }
            pre = i;
        }
        return res;
    }
};
