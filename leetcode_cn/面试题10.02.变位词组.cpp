/*
编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。

注意：本题相对原题稍作修改

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams-lcci
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int rec[26] = {0};
        map<string, vector<string>> m;
        for (auto& s : strs) {
            memset(rec, 0, sizeof(rec));
            for (auto ch : s) {
                ++rec[ch - 'a'];
            }
            string str((const char*)&rec, sizeof(rec));
            m[str].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& p : m) {
            sort(p.second.begin(), p.second.end());
            res.push_back({});
            res.back().swap(p.second);
        }
        return res;
    }
};
