/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
*/
// 首先计算空格的个数
// 在原字符串基础上，计算替换后的空间
// 从尾部向前遍历，拷贝到新的字符串尾部
class Solution {
public:
    string replaceSpace(string s) {
        int n = 0;
        for (auto ch : s) {
            if (ch == ' ') ++n;
        }
        if (0 == n) return s;

        size_t len = s.size();
        size_t new_size = len + 2 * n;
        int idx = new_size - 1;
        string str("%20");

        s.resize(new_size);
        for (int i = len - 1; i >= 0 && n > 0; --i) {
            if (s[i] != ' ') {
                s[idx] = s[i];
                --idx;
                continue;
            }
            for (int j = str.size() - 1; j >= 0; --j) {
                s[idx] = str[j];
                --idx;
            }
            --n;
        }
        return s;
    }
};
