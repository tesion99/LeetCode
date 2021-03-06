/*
给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。

 

示例 1：

输入：nums = [12,345,2,6,7896]
输出：2
解释：
12 是 2 位数字（位数为偶数） 
345 是 3 位数字（位数为奇数）  
2 是 1 位数字（位数为奇数） 
6 是 1 位数字 位数为奇数） 
7896 是 4 位数字（位数为偶数）  
因此只有 12 和 7896 是位数为偶数的数字
示例 2：

输入：nums = [555,901,482,1771]
输出：1 
解释： 
只有 1771 是位数为偶数的数字。
 

提示：

1 <= nums.length <= 500
1 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits
*/
// 本题解法有三
// 1. 统计每个数字的位数做判断
// 2. 将数字转为字符串，判断字符串的长度
// 3. 由于数组中值的范围已经确定，直接列出位数为偶数的数字范围，判断数值是否位于区间中
// 这里采用第3种方法实现
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto n : nums) {
            if ((n >= 10 && n < 100 ) ||
                (n >= 1000 && n < 10000) || 
                (n >= 100000 && n < 1000000)) {
                ++res;
            }
        }
        return res;
    }
};
