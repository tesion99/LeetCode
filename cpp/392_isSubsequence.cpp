/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1:
s = "abc", t = "ahbgdc"

返回 true.

示例 2:
s = "axc", t = "ahbgdc"

返回 false.

后续挑战 :

如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-subsequence
*/
// 遍历t，比对t中当前字符是否与s索引指定的字符相同，若相同，则s索引向前移动
// 最终比对s索引值是否与s长度相等
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int start = 0;
        for (int i = 0; i < t.size() && start < s.size(); ++i) {
            if (s[start] == t[i]) {
                ++start;
            }
        }
        return start == s.size();
    }
};
