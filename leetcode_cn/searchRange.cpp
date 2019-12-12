/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
----------------------------
Note: 使用二分查找
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        int start = 0, end = sz - 1;
        int i = -1, j = -1;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                // check range;
                i = j = mid;
                while (i >= 0 && nums[i] == target) --i;
                while (j < sz && nums[j] == target) ++j;

                ++i;
                --j;
                break;
            }
        }

        return vector<int>({i, j});
    }
};
