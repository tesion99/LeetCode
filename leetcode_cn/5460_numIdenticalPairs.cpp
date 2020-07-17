/*
给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目。

 

示例 1：

输入：nums = [1,2,3,1,1,3]
输出：4
解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
示例 2：

输入：nums = [1,1,1,1]
输出：6
解释：数组中的每组数字都是好数对
示例 3：

输入：nums = [1,2,3]
输出：0
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-pairs
*/
// hash记录之前相同数字出现的个数，便于与当前数组合
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> m;
        int res = 0;
        for (auto n : nums) {
            auto it = m.find(n);
            if (it == m.end()) {
                m[n] = 1;
            } else {
                res += it->second;
                ++it->second;
            }
        }
        return res;
    }
};
