/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
*/
// 利用首尾双指针，同时查找比对
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            while (start <= end && !isalnum(s[start])) {
                ++start;
            }
            while (start <= end && !isalnum(s[end])) {
                --end;
            }

            if (start > end) {
                break;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            ++start;
            --end;
        }

        return true;
    }
};
