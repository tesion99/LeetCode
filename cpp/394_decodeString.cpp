/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
*/
// 首先选择出遇到数字的每个需要翻倍的section的起点
// 解析n[xxx]这一段section的函数，递归调用自身
// 主体遍历到喜爱个section起点，如此递归
class Solution {
public:
    string decodeString(string s) {
        ostringstream oss;
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            if (!isdigit(s[start])) {
                oss << s[start];
            } else {
                oss << decode(s, start, end);
            }
            ++start;
        }
        return oss.str();
    }

    string decode(const std::string& s, int& start, int end) {
        if (start > end) return "";
        int n = 0;
        while (start <= end && isdigit(s[start])) {
            n = 10 * n + s[start] - '0';
            ++start;
        }
        ostringstream oss, res;
        ++start;
        while (start <= end) {
            if (!isdigit(s[start])) {
                if (s[start] == ']') break;

                oss << s[start];
            } else {
                oss << decode(s, start, end);
            }
            ++start;
        }
        string str = oss.str();
        for (int t = 0; t < n; ++t) {
            res << str;
        }
        return res.str();
    }

};
