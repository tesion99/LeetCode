/*
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
注意:

输入的字符串长度不会超过1000。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
*/
// 回文分两种情况："aba" 或 "aa"
// 当遍历字符串s时，当前字符ch可能是"aba"中的b点，故向两边查找的开始坐标分别为（i,i)
// 当ch是"aa"这类情况时， 向两边查找的开始坐标为(i, i + 1)
// 每次产生的回文数量 = i - x
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int x = i, y = i;
            check(s, x, y);
            res += i - x;
            x = i, y = i + 1;
            check(s, x, y);
            res += i - x;
        }
        return res;
    }
    void check(string& s, int& x, int& y) {
        while (x >= 0 && y < s.size()) {
            if (s[x] != s[y]) {
                break;
            }
            --x;
            ++y;
        }
    }
};
