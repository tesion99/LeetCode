/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers
*/
// 分为3中情况
// 1. 全为非负数
// 2. 全为负数和0
// 3. 正负均有
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int val1 = nums[sz - 1] * nums[0] * nums[1];
        int val2 = nums[sz - 1] * nums[sz - 2] * nums[sz - 3];
        return max(val1, val2);
    }
};

// 使用计数排序
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 计数排序，提升效率
        int arr[2001] = {0};
        for (auto n : nums) {
            ++arr[n + 1000];
        }
        int val1 = 1;
        int i = 0, cnt = 2;
        for (int i = 0; i < 2000 && cnt > 0; ++i) {
            if (arr[i] == 0) continue;
            
            int times = min(arr[i], cnt);
            cnt -= times;
            val1 *= pow(i - 1000, times);
        }

        int last = INT_MAX, val2 = 1;
        cnt = 3;
        for (int i = 2000; i >= 0 && cnt > 0; --i) {
            if (arr[i] == 0) continue;

            int times = min(arr[i], cnt);
            cnt -= times;
            val2 *= pow(i - 1000, times);
            if (last == INT_MAX) {
                last = i - 1000;
            }
        }

        val1 *= last;
        return max(val1, val2);
    }
};
