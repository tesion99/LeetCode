/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

Note:
    类似三数和，先排序，双指针
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        int sz = nums.size();
        for (int i = 0; i <= sz - 3; ++i) {
            int j = i + 1, k = sz - 1;
            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) > abs(tmp - target)) {
                    sum = tmp;
                }
                if (tmp > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return sum;
    }
};
