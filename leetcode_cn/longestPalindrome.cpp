/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
------------------------------------
Note: 
    本题主要解题点在于要区分两种回文形式
        ”aba"
        "bb"
    同时设置好一个独立的解析函数，便于部分代码的复用
*/
class Solution {
public:
    int getPalindromeLen(const char * start, const char * end, const char * left, const char * right) {
        int len = 0;
        if (start == nullptr || end == nullptr) return 0;

        if (left == nullptr || right == nullptr) return 0;

        while (left >= start && right < end) {
            if (*left != *right) break;

            --left;
            ++right;
            ++len;
        }

        return len;
    }

    string longestPalindrome(string s) {
        const char * pStart = s.c_str();
        const char * pEnd = pStart + s.size();
        const char * ptr = nullptr;
        const char * resStart = s.c_str();
        const char * resEnd = s.c_str();

        if (s.size() <= 1) return s;

        int max_len = 0, len = 0;

        for (int i = 1; i < s.size(); ++i) {
            // 从左右两边找，形如"aba"
            ptr = pStart + i;
            len = getPalindromeLen(pStart, pEnd, ptr - 1, ptr + 1);

            if (2 * len + 1 > max_len) {
                max_len = 2 * len + 1;
                resStart = ptr - len;
                resEnd = ptr + len;
            }

            // 从前后开始找，形如"abba"
            len = getPalindromeLen(pStart, pEnd, ptr - 1, ptr);
            if (2 * len > max_len) {
                max_len = 2 * len;
                resStart = ptr - len;
                resEnd = ptr + len - 1;
            }
        } // end for

        if (resStart && resEnd) {
            return string(resStart, resEnd + 1);
        } else {
            return string();
        }
    }
};
