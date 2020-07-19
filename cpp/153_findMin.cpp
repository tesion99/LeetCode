/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
*/
// 二分查找，检测mid是否大于right
// 如果mid > right，表示较小的排序部分在右边
// 如果mid <= right 正常排序，缩小right
// 对mid恰好为最小需额外检测
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int sz = nums.size();
        int left = 0, right = sz - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            // 检测mid是否恰好为最小值
            if (right >= 0 && nums[right] > nums[mid]) {
                return nums[mid];
            }
        }
        return nums[left];
    }
};
