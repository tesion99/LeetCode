/*
给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的所有斐波那契式的序列块，如果不能拆分则返回 []。

示例 1：

输入："123456579"
输出：[123,456,579]
示例 2：

输入: "11235813"
输出: [1,1,2,3,5,8,13]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
*/
// 参考131分隔回文串
// 临时数组 + 整型溢出判断
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        if (S.empty()) {
            return vector<int>();
        }
        vector<int> res, tmp;
        int len = 0;
        backtrace(S, 0, S.size() - 1, len, tmp, res);
        return res;
    }

    void backtrace(string& s, int start, int end, int& len, vector<int>& tmp, vector<int>& res) {
        if (start > end) {
            if (len == s.size() && tmp.size() >= 3) {
                res = tmp;
            }
            return;
        }

        string str;
        size_t sz = tmp.size();
        int num = 0;
        for (int i = start; i <= end; ++i) {
            if(num > INT_MAX/10) {
                return;
            }
            if (num == INT_MAX/10 && (INT_MAX % 10 <= s[i] - '0')) {
                return;
            }

            str.push_back(s[i]);
            if (str.size() >= 2 && str[0] == '0') {
                return;
            }
            num = stoi(str);
            long long sum = 0;
            if (sz >= 2) sum = (long)tmp[sz - 1] + (long)tmp[sz - 2];
            if (sum >= INT_MAX) return;
            if (sz < 2 || (sz >= 2 && sum == num)) {
                len += str.size();
                tmp.push_back(num);
                backtrace(s, i+1, end, len, tmp, res);
                tmp.pop_back();
                len -= str.size();
            }
        }
    }
};
