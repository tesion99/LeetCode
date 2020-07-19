/*
给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：

字符（'a' - 'i'）分别用（'1' - '9'）表示。
字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
返回映射之后形成的新字符串。

题目数据保证映射始终唯一。

 

示例 1：

输入：s = "10#11#12"
输出："jkab"
解释："j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decrypt-string-from-alphabet-to-integer-mapping
*/
// 利用栈，对0-9数字做正常映射，当遇到'#'字符时，弹出2个错误映射的字符，重新压入正确的映射字符即可
class Solution {
public:
    string freqAlphabets(string s) {
        deque<char> dq;
        map<string, char> m;
        ostringstream oss;
        for (char c = 'j'; c <= 'z'; ++c) {
            oss << (int)(c - 'a' + 1) << '#';
            m[oss.str()] = c;
            oss.str("");
        }

        string tmp;
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (s[i] != '#') {
                dq.push_back(s[i] - '1' + 'a');
            } else {
                dq.pop_back();
                dq.pop_back();
                tmp = string(s, i - 2, 3);
                dq.push_back(m[tmp]);
            }
        }
        return string(dq.begin(), dq.end());
    }
};
