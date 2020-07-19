/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/roman-to-integer
*/
// 列举所有非典型的组合值，发现异常的情况下，一个值最多由2个字符组成，其余都是一个字符对应一个值
// 故使用map记录下特定的2字符组成的值，用于遍历时的查找
class Solution {
public:
    int romanToInt(string s) {
        map<string, int> m;
        m["IV"] = 4;
        m["IX"] = 9;
        m["XL"] = 40;
        m["XC"] = 90;
        m["CD"] = 400;
        m["CM"] = 900;
        m["I"] = 1;
        m["V"] = 5;
        m["X"] = 10;
        m["L"] = 50;
        m["C"] = 100;
        m["D"] = 500;
        m["M"] = 1000;

        int sum = 0, value = 0;
        int i = 0, sz = s.size();
        std::string ch;
        while (i < sz) {
            ch.clear();
            ch.push_back(s[i]);
            if (i + 1 < sz) {
                ch.push_back(s[i+1]);
                if (m.find(ch) == m.end()) {
                    ch.pop_back();
                }
            }
            value = m.find(ch)->second;
            sum += value;
            i += ch.size();
        }
        
        return sum;
    }
};
