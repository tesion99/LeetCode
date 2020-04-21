/*
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
*/
class Solution {
public:
    string reverseVowels(string s) {
        set<char> target{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            while (start <= end && target.count(s[start]) == 0) {
                ++start;
            }
            while (end >= start && target.count(s[end]) == 0) {
                --end;
            }
            if (start > end) {
                break;
            }
            swap(s[start], s[end]);
            ++start;
            --end;
        }
        return s;
    }
};
