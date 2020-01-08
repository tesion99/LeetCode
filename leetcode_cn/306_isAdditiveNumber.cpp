/*
累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

示例 1:

输入: "112358"
输出: true 
解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2:

输入: "199100199"
输出: true 
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
进阶:
你如何处理一个溢出的过大的整数输入?



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
*/
// 本题同842题，主要在于边界的溢出检测
// 这里使用最大的数据类型unsigned long long数字存储类型
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) {
            return false;
        }
        vector<unsigned long long> tmp, res;
        int len = 0;
        dfs(num, 0, num.size() - 1, len, tmp, res);
        return !res.empty();
    }
    void dfs(string& s, int start, int end, int& len, vector<unsigned long long>& tmp, vector<unsigned long long>& res) {
        if (!res.empty()) {
            return;
        }

        if (start > end) {
            if (len == s.size() && tmp.size() >= 3) {
                res = tmp;
            }
            return;
        }

        unsigned long long num = 0, sum = 0;
        size_t sz = tmp.size();
        string str;
        for (int i = start; i <= end; ++i) {
            if (num >= ULLONG_MAX/10) {
                return;
            }
            if (num == ULLONG_MAX/10 && ULLONG_MAX%10 < s[i] - '0') {
                return;
            }
            str.push_back(s[i]);
            if (i - start >= 1 && str[0] == '0') {
                return;
            }
            sum = 0;
            if (sz >= 2) {
                unsigned long long rest = ULLONG_MAX - tmp[sz - 1];
                if (tmp[sz - 2] > rest) {
                    return;
                }
                sum = tmp[sz - 1] + tmp[sz - 2];
            }
            num = stoull(str);
            if (sz < 2 || (sz >= 2 && sum == num)) {
                len += str.size();
                tmp.push_back(num);
                dfs(s, i + 1, end, len, tmp, res);
                tmp.pop_back();
                len -= str.size();
            }
        }
    }
};
