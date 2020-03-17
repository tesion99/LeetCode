/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-characters-by-frequency
*/
class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for (auto ch : s) {
            ++m[ch];
        }
        map<int, vector<char>> fm;
        for (auto& p : m) {
            fm[p.second].push_back(p.first);
        }

        string str;
        str.reserve(s.size());
        for (auto it = fm.rbegin(); it != fm.rend(); ++it) {
            for (auto ch : it->second) {
                str.insert(str.end(), it->first, ch);
            }
        }
        return str;
    }
};
