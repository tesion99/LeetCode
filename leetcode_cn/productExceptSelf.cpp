/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        int i = 0, j = 0, value = 1;
        vector<int> rets(sz, 1);

        while (i < sz) {
            if (j == sz) break;

            value = (j == i) ? 1 : nums[j];

            rets[i] *= value;

            if (i == sz - 1) {
                i = 0;
                ++j;
                continue;
            }

            ++i;
        }

        return rets;
    }
};

/*
 * 将第i个数的结果分为 i之前的所有数的乘积(left) 与 i之后的所有数的乘积(right)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> rets(sz, 1);

        int left = 1, right = 1;

        // 记录左边第i个数左边的乘积，同时达到复用之前的结果
        // 避免重复，导致效率低下
        for (int i = 0; i < sz; ++i) {
            rets[i] = left;
            left *= nums[i];
        }

        for (int i = sz - 1; i >= 0; --i) {
            rets[i] *= right;
            right *= nums[i];
        }

        return rets;
    }
};
