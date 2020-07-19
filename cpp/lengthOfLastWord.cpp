/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') --i;

        if (i == -1) return 0;

        int start = i;
        for (; i >=0; --i) {
            if (s[i] == ' ') break;
        }
        return start - i;
    }
};
