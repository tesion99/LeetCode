/*
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

示例 1：
输入：text = "nlaebolko"
输出：1

提示：

1 <= text.length <= 10^4
text 全部由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-balloons
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.empty()) {
            return 0;
        }

        map<char, int> m = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
        for (auto ch : text) {
            if (m.count(ch)) {
                ++m[ch];
            }
        }

        int res = INT_MAX;
        for (auto& p : m) {
            int cnt = p.second;
            if (p.first == 'l' || p.first == 'o') {
                cnt = p.second / 2;
            }
            res = min(res, cnt);
        }

        return res;
    }
};
