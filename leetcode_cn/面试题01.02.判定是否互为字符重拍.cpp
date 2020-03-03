/*
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true 
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false
说明：

0 <= len(s1) <= 100
0 <= len(s2) <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-permutation-lcci
*/
// 互为重拍的条件
// 1. 字符串长度相同
// 2. 每个字符出现的次数相同
// 由于字符串使用ascii码，最多256个字符，故使用索引计数方式
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1.empty() && s2.empty()) {
            return true;
        }

        char rec1[256] = {0};
        char rec2[256] = {0};

        for (auto ch : s1) ++rec1[ch];
        for (auto ch : s2) ++rec2[ch];
        for (int i = 0; i < 256; ++i) {
            if (rec1[i] != rec2[i]) {
                return false;
            }
        }
        return true;
    }
};
