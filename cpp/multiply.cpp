/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
-------------------------------
Note:
    参照普通两个数字相乘的原理, 先分别单个相乘，在将每个位上的结果相加
*/

class Solution {
public:
    string singleMultiply(char num, const string & nums) {
        if ('0' == num) return "0";

        string res;
        int val = 0;
        int mul = num - '0';
        int carry = 0;
        int tmp = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            tmp = mul * (nums[i] - '0') + carry;
            carry = tmp / 10;
            res.push_back('0' + tmp % 10);
        }

        if (carry) res.push_back('0' + carry);

        reverse(res.begin(), res.end());
        return res;
    }

    string add(const string & num1, const string & num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        int tmp = 0;
        string res;
        int v1, v2;

        while (i >= 0 || j >= 0) {
            if (i < 0 && j < 0) break;

            v1 = (i >= 0) ? (num1[i] - '0') : 0;
            v2 = (j >= 0) ? (num2[j] - '0') : 0;
            tmp = v1 + v2 + carry;
            carry = tmp / 10;
            res.push_back('0' + tmp % 10);
            --i;
            --j;
        }

        if (carry) res.push_back('0' + carry);

        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {
        if ("0" == num1 || "0" == num2) return "0";
        string res;
        int sz = num1.size();
        string tmp;
        
        for (int i = num1.size() - 1; i >= 0; --i) {
            if ('0' == num1[i]) continue;

            tmp = singleMultiply(num1[i], num2);
            tmp.append(sz - 1 - i, '0');
            
            if (res.empty()) {
                res = tmp;
                continue;
            }

            res = add(tmp, res);
        }

        return res;
    }
};
