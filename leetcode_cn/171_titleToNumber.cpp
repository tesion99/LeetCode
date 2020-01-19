/*
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-number
*/
class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) {
            return 0;
        }

        // 防止int型溢出
        long res = 0;
        for (auto ch : s) {
            res = 26 * res + ch - 'A' + 1;
        }
        return res;
    }
};
