/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
*/
// 观察规律，把字符串从头到尾确定行号
// 当行号达到指定行数时，行号递减；当行数达到0时，行数递增
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        size_t sz = s.size();
        res.reserve(sz);
        for (int row = 0; row < numRows; ++row) {
            int i = row;
            int cur = row;
            int flag = 1;
            while (i < sz) {
                if (cur == row) {
                    res.push_back(s[i]);
                }
                if (cur == numRows - 1) {
                    flag = -1;
                } 
                if (cur == 0) {
                    flag = 1;
                }
                cur += flag;
                ++i;
            }
        }
        return res;
    }
};

// 仅扫描字符串一次
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        size_t sz = s.size();
        res.reserve(sz);
        vector<vector<char>> rows(numRows, vector<char>());
        int curRow = 0;
        int flag = 1;
        for (int i = 0; i < sz; ++i) {
            rows[curRow].push_back(s[i]);
            if (curRow == numRows - 1) {
                flag = -1;
            }
            if (curRow == 0) {
                flag = 1;
            }
            curRow += flag;
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0, sz = rows[i].size(); j < sz; ++j) {
                res.push_back(rows[i][j]);
            }
        }
        return res;
    }
};
