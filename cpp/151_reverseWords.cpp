/*
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

进阶：

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
*/
// 先翻转整个句子，在翻转每个单词
class Solution {
public:
    string reverseWords(string s) {
        s = trim(s);
        if (s.empty()) {
            return s;
        }
        reverse(s, 0, s.size() - 1);
        int i = 0, sz = s.size();
        while (i < sz) {
            while(s[i] == ' ') ++i;
            if (i == sz) {
                break;
            }
            int j = i + 1;
            while (j < sz && s[j] != ' ') ++j;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
    void reverse(string& s, int start, int end) {
        if (start < 0 || start >= s.size() || end < 0 || end >= s.size() || start >= end) {
            return;
        }
        while (start < end) {
            swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
    string trim(string& s) {
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') ++start;

        if (start == s.size()) {
            return string();
        }

        while (end >= start && s[end] == ' ') --end;
        if (end < 0) {
            return string();
        }
        int idx = start;
        for (int i = start; i <= end; ++i) {
            if (i > start && s[i - 1] == ' ' && s[i] == ' ') {
                continue;
            }
            s[idx] = s[i];
            ++idx;
        }
        return s.substr(start, idx - start);
    }
};
