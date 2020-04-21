/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
*/
// 普通查找思路，后续可改用KMP算法查找
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int hs = haystack.size(), ns = needle.size();
        if (hs < ns) {
            return -1;
        }
        for (int i = 0; i <= hs - ns; ++i) {
            int j = 0;
            for (int k = i; j < ns; ++j, ++k) {
                if (needle[j] != haystack[k]) {
                    break;
                }
            }
            if (j == ns) {
                return i;
            }
        }
        return -1;
    }

};
