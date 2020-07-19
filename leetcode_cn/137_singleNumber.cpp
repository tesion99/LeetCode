/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
*/
// hash计数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (auto n : nums) {
            if (m[n] == 2) {
                m.erase(n);
            } else {
                ++m[n];
            }
        }
        return m.begin()->first;
    }
};

// 借助局部变量，计算每个bit为1出现次数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // 使用nums中的2个数字记录bit位
        long flag = 1;
        int cnt = 0;
        int res = 0;
        for (int bit = 0; bit < 32; bit++) {
            cnt = 0;
            for (auto n : nums) {
                if (n & flag) {
                    ++cnt;
                }
                if (cnt % 3 == 0) {
                    cnt = 0;
                }
            }
            if (cnt == 1) {
                res |= flag;
            }
            flag <<= 1;
        }
        return res;
    }
};
