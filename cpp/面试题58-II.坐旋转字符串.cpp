/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。

请定义一个函数实现字符串左旋转操作的功能。


比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000
*/
// 将元字符串看做两部分xy，旋转后的字符串为yx
// 为得到yx，将元字符串加上自身，得到xyxy，在截取子串即可
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (s.empty() || (n % s.size() == 0)) {
            return s;
        }

        int sz = s.size();
        n %= sz;
        s += s;
        return s.substr(n, sz);
    }
};
