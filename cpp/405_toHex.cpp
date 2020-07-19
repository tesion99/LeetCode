/*
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:

十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
示例 1：

输入:
26

输出:
"1a"
示例 2：

输入:
-1

输出:
"ffffffff"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal
*/
// 将负数转变为正数，并补充最后高位的符号位1
class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        int n = num;
        char hex[16] = {'0','1','2','3','4','5','6','7','8','9',
                        'a','b','c','d','e','f'};
        if (num < 0) {
            num = num + 1 + INT_MAX;
        }

        deque<char> dq(sizeof(int)*8/4, '0');
        int idx = 0;
        while (num) {
            int mod = num % 16;
            num >>= 4;
            dq[idx] = hex[mod];
            ++idx;
        }
        if (n < 0) {
            int high = dq.back() - '0' + 8;
            dq.back() = hex[high];
        }

        while (!dq.empty()) {
            if (dq.back() != '0') {
                break;
            }
            dq.pop_back();
        }

        reverse(dq.begin(), dq.end());
        return string(dq.begin(), dq.end());
    }
};
