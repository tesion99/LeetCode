/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
*/
// 计数排序，但记录已序的元素格式
// 额外记录当前0之前的1的个数
// 当前2之后的1的个数
// 用于替换之后遇到2或者0时，进行交换
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return;
        }

        int sz = nums.size();
        int start = 0, end = sz - 1;
        int arr[3] = {0};   // 记录已排好序的0，2的数量
        int oneBefore = 0;  // 记录当前0值之前出现的1的情况
        int oneAfter = 0;   // 记录当前2值之后出现的1的情况
        while (start <= end) {
            while (start <= end && nums[start] == 0) {
                if (oneBefore != 0) {
                    swap(nums[start], nums[arr[0]]);
                }
                ++arr[0];
                ++start;
            }
            if (start > end) {
                break;
            }
            
            while (start <= end && nums[end] == 2) {
                if (oneAfter != 0) {
                    swap(nums[end], nums[sz - 1 - arr[2]]);
                }
                ++arr[2];
                --end;
            }

            if (end < start) {
                break;
            }

            if (nums[start] == 2 && nums[end] == 0) {
                swap(nums[start], nums[end]);
            } else if (nums[start] == 1 && nums[end] == 0) {
                swap(nums[start], nums[end]);
                ++oneAfter;
            } else if (nums[start] == 2 && nums[end] == 1) {
                ++oneBefore;
                swap(nums[start], nums[end]);
            } else {
                // 1 1的情况，记录下来
                ++oneBefore;
                ++oneAfter;
                ++start;
                --end;
            }
        }
    }
};
