/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
 

限制：

0 <= s 的长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof
*/
// 记录字符出现次数与第一次出现的索引
class Solution {
public:
    char firstUniqChar(string s) {
        vector<pair<int, int>> rec(26);

        for (int i = 0; i < s.size(); ++i) {
            auto & p = rec[s[i] - 'a'];
            ++p.first;
            if (p.second == 0) {
                p.second = i;
            } 
        }

        int idx = -1;
        for (auto p : rec) {
            if (p.first == 1) {
                idx = (idx < 0) ? p.second : min(idx, p.second);
                if (idx == 0) {
                    return s[idx];
                }
            }
        }

        return (idx == -1) ? ' ' : s[idx];    
    }
};
