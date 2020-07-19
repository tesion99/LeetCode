/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
--------------------------
Note: 回溯法，遍历每个数字的所有可能
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();

        vector<string> res;
        string str;
        map<char, string> digit_map;
        digit_map['2'] = "abc";
        digit_map['3'] = "def";
        digit_map['4'] = "ghi";
        digit_map['5'] = "jkl";
        digit_map['6'] = "mno";
        digit_map['7'] = "pqrs";
        digit_map['8'] = "tuv";
        digit_map['9'] = "wxyz";

        backtrace(digit_map, digits, 0, str, res);
        return res;
    }

    void backtrace(map<char, string>& dm, string digits, int i, string& str, vector<string>& res) {
        if (i == digits.size()) {
            res.push_back(str);
            return;
        }

        auto it = dm.find(digits[i]);
        if (it == dm.end()) {
            return;
        }
        string& letters = it->second;
        for (int j = 0, sz = letters.size(); j < sz; ++j) {
            str.push_back(letters[j]);
            backtrace(dm, digits, i+1, str, res);
            str.pop_back();
        }
    }
};
