/*
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例:

输入: 4, 14, 2

输出: 6

解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意:

数组中元素的范围为从 0到 10^9。
数组的长度不超过 10^4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/total-hamming-distance
*/
// 循环调用汉明距离函数，执行超时
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                res += getHammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }

    int getHammingDistance(int a, int b) {
        int tmp = a ^ b;
        int cnt = 0;
        while (tmp) {
            tmp &= tmp - 1;
            ++cnt;
        }
        return cnt;
    }
};

// 比对比特位bit 0 ~ 31
// 统计所有数中，当前bit位为1的总数
// 当前比特位能够产生的hammingDistance = (nums.size() - oneNum) * oneNum
// 即所有数的当前bit位中，为0的个数 * 为1的个数 = 当前bit位产生的汉明距离
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int res = 0;
        int sz = nums.size();
        long flag = 1;
        for (int bit = 0; bit < 32; ++bit) {
            int ones = 0;
            for (int i = 0; i < sz; ++i) {
                ones += (nums[i] & flag) ? 1 : 0;
            }
            res += (sz - ones) * ones;
            flag <<= 1;
        }
        return res;
    }
};
