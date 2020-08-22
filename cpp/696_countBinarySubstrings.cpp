/*
给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。

示例 1 :

输入: "00110011"
输出: 6
解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

请注意，一些重复出现的子串要计算它们出现的次数。

另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
示例 2 :

输入: "10101"
输出: 4
解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
注意：

s.length 在1到50,000之间。
s 只包含“0”或“1”字符。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
*/
// 压缩连续相同的字符，记录相邻不同字符的个数
// 取相邻字符个数的最小值，累加为结果
class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 1;

        int res = 0;
        vector<int> vec;
        char ch = s[0];
        int cur = 0;
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (ch == s[i]) {
                ++cur;
            }
            if (ch != s[i]){
                vec.push_back(cur);
                cur = 1;
                ch = s[i];
            }
            if (i == sz - 1) {
                vec.push_back(cur);
            }
        }
        
        for (int i = 0, sz = vec.size() - 1; i < sz; ++i) {
            res += min(vec[i], vec[i + 1]);
        }

        return res;
    }
};

// 优化空间
class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 1;

        int res = 0;
        char ch = s[0];
        int pre = 0, cur = 0;
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (ch == s[i]) {
                ++cur;
            }
            if (ch != s[i]){
                res += min(pre, cur);
                pre = cur;
                cur = 1;
                ch = s[i];
            }
            if (i == sz - 1) {
                res += min(pre, cur);
            }
        }

        return res;
    }
};
