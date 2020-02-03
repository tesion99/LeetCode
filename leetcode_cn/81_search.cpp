/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
*/
// 解法同第33题
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mark = 0;
        for (int i = 0, sz = nums.size(); i < sz - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                mark = i + 1;
            }
        }

        return binarySearch(nums, 0, mark - 1, target) || binarySearch(nums, mark, nums.size() - 1, target);
    }
    bool binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
