/*
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]
注意：

S 的长度不超过12。
S 仅由数字和字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
*/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if (S.empty()) {
            return vector<string>();
        }

        vector<string> res;
        convert(S, 0, res);
        return res;
    }

    void convert(string& S, int start, vector<string>& res) {
        if (start == S.size()) {
            res.push_back(S);
            return;
        }
        // 保留元数据
        convert(S, start+1, res);
        // 字符转为大写
        if (S[start] >= 'a' && S[start] <= 'z') {
            S[start] -= 32;
            convert(S, start+1, res);
            S[start] += 32;
        } else if (S[start] >= 'A' && S[start] <= 'Z') {
            S[start] += 32;
            convert(S, start+1, res);
            S[start] -= 32;
        }
    }

};
