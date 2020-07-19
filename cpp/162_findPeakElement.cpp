/*
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
说明:

你的解法应该是 O(logN) 时间复杂度的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
*/
// 模拟quickSort，分治处理左右两部分，从而使时间复杂度符合题目要求
// 要考虑数组已序的特殊情况
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) {
            return 0;
        } else if (sz == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }

        int ret = findPeak(nums, 0, sz - 1);
        // 数组已序
        if (ret == -1) {
            ret = nums[0] > nums[sz - 1] ? 0 : sz - 1;
        }
        return ret;
    }

    int findPeak(vector<int>& nums, int start, int end) {
        if (start < 0 || start >= nums.size() || end < 0 || end >= nums.size()) {
            return -1;
        }

        if (end - start < 2) {
            return -1;
        }

        int mid = (end + start) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        int ret = findPeak(nums, start, mid);
        if (ret == -1) {
            ret = findPeak(nums, mid, end);
        }
        return ret;
    }
};
