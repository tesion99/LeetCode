/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/move-zeroes
--------------------
Note: 根据数组中0的个数，调整对应非零元素到指定的索引处即可
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;

        // 根据非零元素其前面的0的个数，调整新索引
        int before = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == 0) {
                ++before;
                continue;
            }
            if (before == 0) {
                continue;
            }
            int new_idx = i - before;
            nums[new_idx] = nums[i];
        }

        // 全零
        if (before == sz) return;

        for (int i = sz - before; i < sz; ++i) {
            nums[i] = 0;
        }
    }
};
