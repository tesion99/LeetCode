/*
外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
*/
// 因后项是对前项的描述，故使用递归
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n - 1);
        
        int count = 0, sz = s.size();
        string res;
        for (int i = 0; i < sz - 1; ++i) {
            if (s[i] == s[i + 1]) {
                ++count;
            } else {
                ++count;
                res.push_back('0' + count);
                res.push_back(s[i]);
                count = 0;
            }
        }
        ++count; // 最后一个元素
        res.push_back('0' + count);
        res.push_back(s[sz - 1]);
        return res;
    }
};

// 适量改进
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n - 1);

        int count = 1, sz = s.size();
        string res;
        for (int i = 0; i < sz - 1; ++i) {
            if (s[i] == s[i + 1]) {
                ++count;
            } else {
                res.push_back('0' + count);
                res.push_back(s[i]);
                count = 1;
            }
        }
        // 最后元素的计数
        res.push_back('0' + count);
        res.push_back(s[sz - 1]);
        return res;
    }
};
