/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
*/
// 自定义sort的compare方法
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return string();
        }

        sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = to_string(a);
            string sb = to_string(b);
            return sa + sb > sb + sa;
        });

        ostringstream oss;
        for (int i = 0; i < nums.size(); ++i) {
            oss << nums[i];
        }
        string res = oss.str();
        return res[0] == '0' ? "0" : res;
    }
};
