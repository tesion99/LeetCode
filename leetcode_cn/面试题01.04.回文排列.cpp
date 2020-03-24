/*
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。

 

示例1：

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-permutation-lcci
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int record[256] = {0};
        for (auto c : s) {
            if (record[c] > 0) {
                --record[c];
            } else {
                ++record[c];
            }
        }

        int odd = 0;
        for (int i = 0; i < 256; ++i) {
            if (record[i] == 0) continue;

            if (odd == 0) {
                odd = 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
