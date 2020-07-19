/*
给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏。

示例 1:

输入: "PPALLP"
输出: True
示例 2:

输入: "PPALLL"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/student-attendance-record-i
*/
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0, cntL = 0, idx = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                ++cntA;
            } else if (s[i] == 'L') {
                cntL = (idx != i - 1) ? 1 : cntL + 1;
                idx = i;
            }

            if (cntA > 1 || cntL > 2) {
                return false;
            }
        }
        return true;
    }
};
