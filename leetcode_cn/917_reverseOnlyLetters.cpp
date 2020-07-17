/*
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int start = 0, end = S.size() - 1;
        while (start <= end) {
            while (start <= end) {
                if ((S[start] >= 'a' && S[start] <= 'z')
                    || (S[start] >= 'A' && S[start] <= 'Z')) {
                    break;
                }
                ++start;
            }
            while (start <= end) {
                if ((S[end] >= 'a' && S[end] <= 'z')
                    || (S[end] >= 'A' && S[end] <= 'Z')) {
                    break;
                }
                --end;
            }
            if (start < end) {
                swap(S[start], S[end]);
            }
            ++start;
            --end;
        }
        return S;
    }
};
