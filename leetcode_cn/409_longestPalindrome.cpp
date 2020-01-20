/*
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindrome
*/
// hash 统计字符出现个数
class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        map<char, int> m;
        for (auto ch : s) {
            ++m[ch];
        }
        for (auto& it : m) {
            if ((it.second & 1) == 0) {
                len += it.second;
            } else {
                len += it.second - 1;
            }
        }
        return len + (len != s.size() ? 1 : 0);
    }
};

// 优化，本质上只需统计出现奇数次的个数，因为其会剩余1个无法加入到回文中
// 返回 s.size() - odd + 1 // 加一为将剩余的一个奇数次字符放入回文，形成aba的形式
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for (auto ch : s) {
            ++m[ch];
        }
        int odd = 0;
        for (auto& it : m) {
            if (it.second & 1) {
                ++odd;
            }
        }

        return odd == 0 ? s.size() : s.size() - odd + 1;
    }
};
