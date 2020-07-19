/*
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range
*/
// 所有数字按位与，主要由第一个数字确定有效比特位长度
// 此方法执行超时
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) {
            return 0;
        }
        if (m == n) {
            return m;
        }

        int res = m;
        for (long i = m; i <= n && res > 0; ++i) {
            if (i > m && isPowerOfTwo(i)) {
                return 0;
            }
            res &= i;
        }
        return res;
    }

    bool isPowerOfTwo(long n) {
        return (n & n - 1) == 0 ? true : false;
    }
};
/*
从m ~ n的所有数与的结果，由最开始的数m确定，最终结果result <= m
对后续的数中，只需知道是否有能对m为1的bit位置0的数存在即可
考虑二进制数，1011，比其大且能对其中的1进行与操作后，置1为0的数为 1100，然后判断1100是否在 m ~ n之间
如果在m~n之间，则进行操作1011 & 1100 = 1000，继续查找下一个能对1000中1产生置0的数，重复以上操作
如果不存在，证明数据值bit位不会再被改变，可返回结果
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        int len = 0;
        int cur = m;
        // 查找bit位中从右到左第一个为1的位置
        while (cur) {
            if (cur & 1) {
                break;
            }
            ++len;
            cur >>= 1;
        }
        long flag = 1 << len;
        // 寻找到从右第一个1开始，第一个0位置为1的数
        long i = nextNum(res, flag);
        while (i <= n && res > 0) {
            res &= i;
            flag <<= 1;
            i = nextNum(res, flag);
        }
        return res;
    }

    long nextNum(int n, long flag) {
        while (n & flag) {
            flag <<= 1;
            n &= n - 1;
        }
        return n | flag;
    }
};
