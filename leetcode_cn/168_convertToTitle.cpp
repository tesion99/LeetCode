/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/excel-sheet-column-title
*/
// 注意边间 26 52等的考虑
class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        deque<char> dq;
        while (n) {
            int mod = n % 26;
            n /= 26;
            if (mod != 0) {
                dq.push_front('A' + mod - 1);
            } else {
                --n;
                dq.push_front('Z');
                if (n >= 1 && n <= 26) {
                     dq.push_front('A' + n - 1);
                     n = 0;
                }
            }
        }
        return string(dq.begin(), dq.end());
    }
};
