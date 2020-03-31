/*
给定一个整数数组 nums，将该数组升序排列。

 

示例 1：

输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= A.length <= 10000
-50000 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }

        int rec[100001] = {0};
        for (auto& n : nums) {
            ++rec[n + 50000];
        }

        vector<int> res;
        res.reserve(nums.size());
        for (int i = 0; i < 100001; ++i) {
            if (rec[i] <= 0) continue;
            res.insert(res.end(), rec[i], i - 50000);
        }
        return res;
    }
};
