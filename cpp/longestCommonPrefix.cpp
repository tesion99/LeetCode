/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        char tmp;
        int index = 0;
        int sz = strs.size();

        for (int i = 0; i < sz;) {
            if (index >= strs[i].size()) break;

            // 获取当前需要比对的字符
            if (0 == i) {
                tmp = strs[i][index];
            }

            if (tmp != strs[i][index]) break;

            if (i == sz - 1) {
                i = 0;
                ++index;
                prefix.append(1, tmp);
            } else {
                ++i;
            }

        }

        return prefix;
    }
};
