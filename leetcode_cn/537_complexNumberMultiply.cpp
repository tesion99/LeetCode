/*
给定两个表示复数的字符串。

返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:

输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2:

输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
注意:

输入字符串不包含额外的空格。
输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/complex-number-multiplication
*/
// 分别解析出字符串表示中的实部(real)与虚部(image)，相乘得到数字结果
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra = 0, ma = 0;
        int rb = 0, mb = 0;
        getComplexNum(a, ra, ma);
        getComplexNum(b, rb, mb);

        int real = ra * rb - ma * mb;
        int image = ra * mb + rb * ma;
        ostringstream oss;
        oss << real << "+" << image << "i";
        return oss.str();
    }

    void getComplexNum(const std::string& s, int& a, int& b) {
        a = 0;
        b = 0;
        int start = 0, end = s.size() - 1;
        int flag = 1;
        while (start <= end && s[start] != '+') {
            if (s[start] == '-') {
                flag = -1;
            } else {
                a = a * 10 + s[start] - '0';
            }
            ++start;
        }
        a *= flag;
        ++start;
        flag = 1;
        while (start <= end && s[start] != 'i') {
            if (s[start] == '-') {
                flag = -1;
            } else {
                b = b * 10 + s[start] - '0';
            }
            ++start;
        }
        b *= flag;
    }
};
