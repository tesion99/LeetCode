/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。

一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
*/
// 检测每一段数字，满足0-25时，继续递归检测后续剩余数字，直到完毕
class Solution {
public:
    int translateNum(int num) {
        std::string s = to_string(num);
        int res = 0;
        translate(s, 0, s.size(), res);
        return res;
    }

    void translate(const std::string& s, int cur, int end, int& res) {
        if (cur >= end) {
            ++res;
            return;
        }

        int num = 0;
        for (int i = cur; i < end; ++i) {
            num = num * 10 + s[i] - '0';
            if (num == 0) {
                translate(s, i + 1, end, res);
                break;
            }
            if (num > 25) {
                break;
            }
            translate(s, i + 1, end, res);
        }
    }
};
