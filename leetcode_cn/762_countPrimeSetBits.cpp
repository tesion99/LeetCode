/*
给定两个整数 L 和 R ，找到闭区间 [L, R] 范围内，计算置位位数为质数的整数个数。

（注意，计算置位代表二进制表示中1的个数。例如 21 的二进制表示 10101 有 3 个计算置位。还有，1 不是质数。）

示例 1:

输入: L = 6, R = 10
输出: 4
解释:
6 -> 110 (2 个计算置位，2 是质数)
7 -> 111 (3 个计算置位，3 是质数)
9 -> 1001 (2 个计算置位，2 是质数)
10-> 1010 (2 个计算置位，2 是质数)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation
*/
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt = 0;
        vector<int> data = {2, 3, 5, 7, 11, 13};
        for (int i = L; i <= R; ++i) {
            int bits = getBits(i);
            if (check(data, bits)) {
                ++cnt;
            }
        }
        return cnt;
    }
    int getBits(int num) {
        int cnt = 0;
        while (num) {
            ++cnt;
            num &= num - 1;
        }
        return cnt;
    }
    bool check (vector<int>& nums, int n) {
        if (n == 1) {
            return false;
        }
        int mid = sqrt(n);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mid) {
                break;
            }
            if (n % nums[i] == 0) {
                return false;
            }
        }
        nums.push_back(n);
        return true;
    }
};
