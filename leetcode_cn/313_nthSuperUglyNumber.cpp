/*
编写一段程序来查找第 n 个超级丑数。

超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

示例:

输入: n = 12, primes = [2,7,13,19]
输出: 32 
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
说明:

1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。
*/
// 类似264题解法
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int res = 0;
        set<long> s;
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                res = 1;
                continue;
            }
            for (int j = 0; j < primes.size(); ++j) {
                s.insert((long)primes[j] * res);
            }
            if (!s.empty()) {
                res = *s.begin();
                s.erase(s.begin());
            }
        }
        return res;
    }
};
