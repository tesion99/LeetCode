/*
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

示例：

输入:
[4,3,2,7,8,2,3,1]

输出:
[2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
*/
// 根据a[i]值的特殊性，将a[i]放置到数组中对应的第a[i]个位置
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<int>();
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i + 1) {
                continue;
            }
            
            while (nums[i] != i + 1 && nums[i] != 0) {
                if (nums[nums[i] - 1] == nums[i]) {
                    res.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                }
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return res;
    }
};
