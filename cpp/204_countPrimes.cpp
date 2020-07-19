/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
// 每轮判断保存新增的质数
// 每次用已经保存的质数，与新的数相除
class Solution {
public:
    int countPrimes(int n) {
        set<int> s;
        for (int i = 1; i < n; ++i) {
            if (isPrime(i, s)) {
                s.insert(i);
            }
        }
        return s.size();
    }
    bool isPrime(int n, set<int>& s) {
        if (n <= 1) {
            return false;
        }

        int limit = sqrt(n);
        for (auto it = s.begin(); it != s.end() && *it <= limit; ++it) {
            if (n % *it == 0) {
                return false;
            }
        }
        return true;
    }
};
