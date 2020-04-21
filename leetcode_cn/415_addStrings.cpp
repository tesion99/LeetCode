/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) {
            return num2;
        } else if (num2.empty()) {
            return num1;
        }
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;

        string res;
        while (i >= 0 || j >= 0) {
            if (i < 0 && j < 0) break;

            int val1 = (i < 0) ? 0 : num1[i] - '0';
            int val2 = (j < 0) ? 0 : num2[j] - '0';
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum %= 10;
            res.push_back('0' + sum);
            --i;
            --j;
        }
        if (carry) {
            res.push_back('0' + carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
