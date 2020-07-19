/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
*/
// 原地resize数组，整体向后移动K后，再把超出的部分移动头部前K个位置
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() == 1 || k <= 0) {
            return;
        }
        size_t sz = nums.size();
        k %= sz;
        nums.resize(sz + k);    // 该数组尾部扩增，存储需要右移的元素
        // 整体右移K
        for (int i = sz - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        // 超过SZ长度的元素放于头部
        for (int i = sz + k - 1; i > sz - 1; --i) {
            nums[i%sz] = nums[i];
        }
        nums.resize(sz);
    }
};
