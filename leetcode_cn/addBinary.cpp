/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
------------------
Note: 对string字符串结果，提前进行预分配，提高效率
*/
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) return b;
        if (b.empty()) return a;

        string res;
        res.reserve(a.size() > b.size() ? (a.size() + 1) : (b.size() + 1));
        int la = a.size() - 1, lb = b.size() - 1;
        int va = 0, vb = 0, carray = 0, tmp = 0;
        while (la >= 0 || lb >= 0) {
            if (la < 0 && lb < 0) {
                break;
            }

            va = (la >= 0) ? (a[la] - '0') : 0;
            vb = (lb >= 0) ? (b[lb] - '0') : 0;
            tmp = va + vb + carray;
            carray = tmp / 2;
            res.push_back('0' + tmp % 2);
            --la;
            --lb;
        }

        if (carray != 0) {
            res.push_back('0' + carray);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
