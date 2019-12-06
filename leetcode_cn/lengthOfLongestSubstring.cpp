/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
Ps:
    从头开始扫描，没有找到重复字符时，继续向后查找，否则更新字符串起始指针
*/

class Solution {
public:
    const char * findChar(const char * ps, const char * pe)
    {
        if (!ps) return nullptr;

        while (ps < pe)
        {
            if (*ps == *pe)
            {
                return ps;
            }

            ++ps;
        }

        return nullptr;
    }

    int lengthOfLongestSubstring(string s) {
        const char * ps = s.c_str();
        const char * pe = ps;
        const char * pend = s.c_str() + s.size();
        const char * pos = nullptr;
        int max_len = 0;
        int len = 0;
        while (pe <= pend)
        {
            pos = (pe != pend) ? findChar(ps, pe) : nullptr;
            len = pe - ps;

            if (len > max_len)
            {
                max_len = len;
            }

            if (pos)
            {
                ps = pos + 1;
            }

            ++pe;
        }

        return max_len;
    }
};
